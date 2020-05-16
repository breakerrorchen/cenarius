#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_rsa.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/main_test.function
 *      Platform code file  : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/host_test.function
 *      Helper file         : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/helpers.function
 *      Test suite file     : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function
 *      Test suite data     : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.data
 *
 *
 *  This file is part of Mbed TLS (https://tls.mbed.org)
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include <mbedtls/config.h>
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_USE_PSA_CRYPTO)
#include "psa/crypto.h"
#endif /* MBEDTLS_USE_PSA_CRYPTO */

/* Test code may use deprecated identifiers only if the preprocessor symbol
 * MBEDTLS_TEST_DEPRECATED is defined. When building tests, set
 * MBEDTLS_TEST_DEPRECATED explicitly if MBEDTLS_DEPRECATED_WARNING is
 * enabled but the corresponding warnings are not treated as errors.
 */
#if !defined(MBEDTLS_DEPRECATED_REMOVED) && !defined(MBEDTLS_DEPRECATED_WARNING)
#define MBEDTLS_TEST_DEPRECATED
#endif

/*----------------------------------------------------------------------------*/
/* Common helper code */

#line 2 "suites/helpers.function"
/*----------------------------------------------------------------------------*/
/* Headers */

#include <stdlib.h>

#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_fprintf    fprintf
#define mbedtls_snprintf   snprintf
#define mbedtls_calloc     calloc
#define mbedtls_free       free
#define mbedtls_exit       exit
#define mbedtls_time       time
#define mbedtls_time_t     time_t
#define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif

#if defined(MBEDTLS_CHECK_PARAMS)
#include "mbedtls/platform_util.h"
#include <setjmp.h>
#endif

#ifdef _MSC_VER
#include <basetsd.h>
typedef UINT8 uint8_t;
typedef INT32 int32_t;
typedef UINT32 uint32_t;
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#else
#include <stdint.h>
#endif

#include <string.h>

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#include <strings.h>
#endif

/* Type for Hex parameters */
typedef struct data_tag
{
    uint8_t *   x;
    uint32_t    len;
} data_t;

/*----------------------------------------------------------------------------*/
/* Status and error constants */

#define DEPENDENCY_SUPPORTED            0   /* Dependency supported by build */
#define KEY_VALUE_MAPPING_FOUND         0   /* Integer expression found */
#define DISPATCH_TEST_SUCCESS           0   /* Test dispatch successful */

#define KEY_VALUE_MAPPING_NOT_FOUND     -1  /* Integer expression not found */
#define DEPENDENCY_NOT_SUPPORTED        -2  /* Dependency not supported */
#define DISPATCH_TEST_FN_NOT_FOUND      -3  /* Test function not found */
#define DISPATCH_INVALID_TEST_DATA      -4  /* Invalid test parameter type.
                                               Only int, string, binary data
                                               and integer expressions are
                                               allowed */
#define DISPATCH_UNSUPPORTED_SUITE      -5  /* Test suite not supported by the
                                               build */

typedef enum
{
    PARAMFAIL_TESTSTATE_IDLE = 0,           /* No parameter failure call test */
    PARAMFAIL_TESTSTATE_PENDING,            /* Test call to the parameter failure
                                             * is pending */
    PARAMFAIL_TESTSTATE_CALLED              /* The test call to the parameter
                                             * failure function has been made */
} paramfail_test_state_t;


/*----------------------------------------------------------------------------*/
/* Macros */

/**
 * \brief   This macro tests the expression passed to it as a test step or
 *          individual test in a test case.
 *
 *          It allows a library function to return a value and return an error
 *          code that can be tested.
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), will be assumed to be a test
 *          failure.
 *
 *          This macro is not suitable for negative parameter validation tests,
 *          as it assumes the test step will not create an error.
 *
 *          Failing the test means:
 *          - Mark this test case as failed.
 *          - Print a message identifying the failure.
 *          - Jump to the \c exit label.
 *
 *          This macro expands to an instruction, not an expression.
 *          It may jump to the \c exit label.
 *
 * \param   TEST    The test expression to be tested.
 */
#define TEST_ASSERT( TEST )                                 \
    do {                                                    \
       if( ! (TEST) )                                       \
       {                                                    \
          test_fail( #TEST, __LINE__, __FILE__ );           \
          goto exit;                                        \
       }                                                    \
    } while( 0 )

/** Evaluate two expressions and fail the test case if they have different
 * values.
 *
 * \param expr1     An expression to evaluate.
 * \param expr2     The expected value of \p expr1. This can be any
 *                  expression, but it is typically a constant.
 */
#define TEST_EQUAL( expr1, expr2 )              \
    TEST_ASSERT( ( expr1 ) == ( expr2 ) )

/** Allocate memory dynamically and fail the test case if this fails.
 *
 * You must set \p pointer to \c NULL before calling this macro and
 * put `mbedtls_free( pointer )` in the test's cleanup code.
 *
 * If \p length is zero, the resulting \p pointer will be \c NULL.
 * This is usually what we want in tests since API functions are
 * supposed to accept null pointers when a buffer size is zero.
 *
 * This macro expands to an instruction, not an expression.
 * It may jump to the \c exit label.
 *
 * \param pointer   An lvalue where the address of the allocated buffer
 *                  will be stored.
 *                  This expression may be evaluated multiple times.
 * \param length    Number of elements to allocate.
 *                  This expression may be evaluated multiple times.
 *
 */
#define ASSERT_ALLOC( pointer, length )                           \
    do                                                            \
    {                                                             \
        TEST_ASSERT( ( pointer ) == NULL );                       \
        if( ( length ) != 0 )                                     \
        {                                                         \
            ( pointer ) = mbedtls_calloc( sizeof( *( pointer ) ), \
                                          ( length ) );           \
            TEST_ASSERT( ( pointer ) != NULL );                   \
        }                                                         \
    }                                                             \
    while( 0 )

/** Allocate memory dynamically. If the allocation fails, skip the test case.
 *
 * This macro behaves like #ASSERT_ALLOC, except that if the allocation
 * fails, it marks the test as skipped rather than failed.
 */
#define ASSERT_ALLOC_WEAK( pointer, length )                      \
    do                                                            \
    {                                                             \
        TEST_ASSERT( ( pointer ) == NULL );                       \
        if( ( length ) != 0 )                                     \
        {                                                         \
            ( pointer ) = mbedtls_calloc( sizeof( *( pointer ) ), \
                                          ( length ) );           \
            TEST_ASSUME( ( pointer ) != NULL );                   \
        }                                                         \
    }                                                             \
    while( 0 )

/** Compare two buffers and fail the test case if they differ.
 *
 * This macro expands to an instruction, not an expression.
 * It may jump to the \c exit label.
 *
 * \param p1        Pointer to the start of the first buffer.
 * \param size1     Size of the first buffer in bytes.
 *                  This expression may be evaluated multiple times.
 * \param p2        Pointer to the start of the second buffer.
 * \param size2     Size of the second buffer in bytes.
 *                  This expression may be evaluated multiple times.
 */
#define ASSERT_COMPARE( p1, size1, p2, size2 )                          \
    do                                                                  \
    {                                                                   \
        TEST_ASSERT( ( size1 ) == ( size2 ) );                          \
        if( ( size1 ) != 0 )                                            \
            TEST_ASSERT( memcmp( ( p1 ), ( p2 ), ( size1 ) ) == 0 );    \
    }                                                                   \
    while( 0 )

/**
 * \brief   This macro tests the expression passed to it and skips the
 *          running test if it doesn't evaluate to 'true'.
 *
 * \param   TEST    The test expression to be tested.
 */
#define TEST_ASSUME( TEST )                         \
    do {                                            \
        if( ! (TEST) )                              \
        {                                           \
            test_skip( #TEST, __LINE__, __FILE__ ); \
            goto exit;                              \
        }                                           \
    } while( 0 )

#if defined(MBEDTLS_CHECK_PARAMS) && !defined(MBEDTLS_PARAM_FAILED_ALT)
/**
 * \brief   This macro tests the statement passed to it as a test step or
 *          individual test in a test case. The macro assumes the test will fail
 *          and will generate an error.
 *
 *          It allows a library function to return a value and tests the return
 *          code on return to confirm the given error code was returned.
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), are assumed to indicate the
 *          expected failure, and the test will pass.
 *
 *          This macro is intended for negative parameter validation tests,
 *          where the failing function may return an error value or call
 *          MBEDTLS_PARAM_FAILED() to indicate the error.
 *
 * \param   PARAM_ERROR_VALUE   The expected error code.
 *
 * \param   TEST                The test expression to be tested.
 */
#define TEST_INVALID_PARAM_RET( PARAM_ERR_VALUE, TEST )                     \
    do {                                                                    \
        test_info.paramfail_test_state = PARAMFAIL_TESTSTATE_PENDING;       \
        if( (TEST) != (PARAM_ERR_VALUE) ||                                  \
            test_info.paramfail_test_state != PARAMFAIL_TESTSTATE_CALLED )  \
        {                                                                   \
            test_fail( #TEST, __LINE__, __FILE__ );                         \
            goto exit;                                                      \
        }                                                                   \
   } while( 0 )

/**
 * \brief   This macro tests the statement passed to it as a test step or
 *          individual test in a test case. The macro assumes the test will fail
 *          and will generate an error.
 *
 *          It assumes the library function under test cannot return a value and
 *          assumes errors can only be indicated byt calls to
 *          MBEDTLS_PARAM_FAILED().
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), are assumed to indicate the
 *          expected failure. If MBEDTLS_CHECK_PARAMS is not enabled, no test
 *          can be made.
 *
 *          This macro is intended for negative parameter validation tests,
 *          where the failing function can only return an error by calling
 *          MBEDTLS_PARAM_FAILED() to indicate the error.
 *
 * \param   TEST                The test expression to be tested.
 */
#define TEST_INVALID_PARAM( TEST )                                          \
    do {                                                                    \
        memcpy(jmp_tmp, param_fail_jmp, sizeof(jmp_buf));                   \
        if( setjmp( param_fail_jmp ) == 0 )                                 \
        {                                                                   \
            TEST;                                                           \
            test_fail( #TEST, __LINE__, __FILE__ );                         \
            goto exit;                                                      \
        }                                                                   \
        memcpy(param_fail_jmp, jmp_tmp, sizeof(jmp_buf));                   \
    } while( 0 )
#endif /* MBEDTLS_CHECK_PARAMS && !MBEDTLS_PARAM_FAILED_ALT */

/**
 * \brief   This macro tests the statement passed to it as a test step or
 *          individual test in a test case. The macro assumes the test will not fail.
 *
 *          It assumes the library function under test cannot return a value and
 *          assumes errors can only be indicated by calls to
 *          MBEDTLS_PARAM_FAILED().
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), are assumed to indicate the
 *          expected failure. If MBEDTLS_CHECK_PARAMS is not enabled, no test
 *          can be made.
 *
 *          This macro is intended to test that functions returning void
 *          accept all of the parameter values they're supposed to accept - eg
 *          that they don't call MBEDTLS_PARAM_FAILED() when a parameter
 *          that's allowed to be NULL happens to be NULL.
 *
 *          Note: for functions that return something other that void,
 *          checking that they accept all the parameters they're supposed to
 *          accept is best done by using TEST_ASSERT() and checking the return
 *          value as well.
 *
 *          Note: this macro is available even when #MBEDTLS_CHECK_PARAMS is
 *          disabled, as it makes sense to check that the functions accept all
 *          legal values even if this option is disabled - only in that case,
 *          the test is more about whether the function segfaults than about
 *          whether it invokes MBEDTLS_PARAM_FAILED().
 *
 * \param   TEST                The test expression to be tested.
 */
#define TEST_VALID_PARAM( TEST )                                    \
    TEST_ASSERT( ( TEST, 1 ) );

#define TEST_HELPER_ASSERT(a) if( !( a ) )                          \
{                                                                   \
    mbedtls_fprintf( stderr, "Assertion Failed at %s:%d - %s\n",    \
                             __FILE__, __LINE__, #a );              \
    mbedtls_exit( 1 );                                              \
}

#if defined(__GNUC__)
/* Test if arg and &(arg)[0] have the same type. This is true if arg is
 * an array but not if it's a pointer. */
#define IS_ARRAY_NOT_POINTER( arg )                                     \
    ( ! __builtin_types_compatible_p( __typeof__( arg ),                \
                                      __typeof__( &( arg )[0] ) ) )
#else
/* On platforms where we don't know how to implement this check,
 * omit it. Oh well, a non-portable check is better than nothing. */
#define IS_ARRAY_NOT_POINTER( arg ) 1
#endif

/* A compile-time constant with the value 0. If `const_expr` is not a
 * compile-time constant with a nonzero value, cause a compile-time error. */
#define STATIC_ASSERT_EXPR( const_expr )                                \
    ( 0 && sizeof( struct { int STATIC_ASSERT : 1 - 2 * ! ( const_expr ); } ) )
/* Return the scalar value `value` (possibly promoted). This is a compile-time
 * constant if `value` is. `condition` must be a compile-time constant.
 * If `condition` is false, arrange to cause a compile-time error. */
#define STATIC_ASSERT_THEN_RETURN( condition, value )   \
    ( STATIC_ASSERT_EXPR( condition ) ? 0 : ( value ) )

#define ARRAY_LENGTH_UNSAFE( array )            \
    ( sizeof( array ) / sizeof( *( array ) ) )
/** Return the number of elements of a static or stack array.
 *
 * \param array         A value of array (not pointer) type.
 *
 * \return The number of elements of the array.
 */
#define ARRAY_LENGTH( array )                                           \
    ( STATIC_ASSERT_THEN_RETURN( IS_ARRAY_NOT_POINTER( array ),         \
                                 ARRAY_LENGTH_UNSAFE( array ) ) )

/** Return the smaller of two values.
 *
 * \param x         An integer-valued expression without side effects.
 * \param y         An integer-valued expression without side effects.
 *
 * \return The smaller of \p x and \p y.
 */
#define MIN( x, y ) ( ( x ) < ( y ) ? ( x ) : ( y ) )

/** Return the larger of two values.
 *
 * \param x         An integer-valued expression without side effects.
 * \param y         An integer-valued expression without side effects.
 *
 * \return The larger of \p x and \p y.
 */
#define MAX( x, y ) ( ( x ) > ( y ) ? ( x ) : ( y ) )

/** Allocate memory dynamically and fail the test case if this fails.
 *
 * You must set \p pointer to \c NULL before calling this macro and
 * put `mbedtls_free( pointer )` in the test's cleanup code.
 *
 * If \p length is zero, the resulting \p pointer will be \c NULL.
 * This is usually what we want in tests since API functions are
 * supposed to accept null pointers when a buffer size is zero.
 *
 * This macro expands to an instruction, not an expression.
 * It may jump to the \c exit label.
 *
 * \param pointer   An lvalue where the address of the allocated buffer
 *                  will be stored.
 *                  This expression may be evaluated multiple times.
 * \param length    Number of elements to allocate.
 *                  This expression may be evaluated multiple times.
 *
 */
#define ASSERT_ALLOC( pointer, length )                           \
    do                                                            \
    {                                                             \
        TEST_ASSERT( ( pointer ) == NULL );                       \
        if( ( length ) != 0 )                                     \
        {                                                         \
            ( pointer ) = mbedtls_calloc( sizeof( *( pointer ) ), \
                                          ( length ) );           \
            TEST_ASSERT( ( pointer ) != NULL );                   \
        }                                                         \
    }                                                             \
    while( 0 )

/*
 * 32-bit integer manipulation macros (big endian)
 */
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
{                                                       \
    (n) = ( (uint32_t) (b)[(i)    ] << 24 )             \
        | ( (uint32_t) (b)[(i) + 1] << 16 )             \
        | ( (uint32_t) (b)[(i) + 2] <<  8 )             \
        | ( (uint32_t) (b)[(i) + 3]       );            \
}
#endif

#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
{                                                       \
    (b)[(i)    ] = (unsigned char) ( (n) >> 24 );       \
    (b)[(i) + 1] = (unsigned char) ( (n) >> 16 );       \
    (b)[(i) + 2] = (unsigned char) ( (n) >>  8 );       \
    (b)[(i) + 3] = (unsigned char) ( (n)       );       \
}
#endif


/*----------------------------------------------------------------------------*/
/* Global variables */

typedef enum
{
    TEST_RESULT_SUCCESS = 0,
    TEST_RESULT_FAILED,
    TEST_RESULT_SKIPPED
} test_result_t;

typedef struct
{
    paramfail_test_state_t paramfail_test_state;
    test_result_t result;
    const char *test;
    const char *filename;
    int line_no;
    unsigned long step;
}
test_info_t;
static test_info_t test_info;

#if defined(MBEDTLS_PLATFORM_C)
mbedtls_platform_context platform_ctx;
#endif

#if defined(MBEDTLS_CHECK_PARAMS)
jmp_buf param_fail_jmp;
jmp_buf jmp_tmp;
#endif

/*----------------------------------------------------------------------------*/
/* Helper flags for complex dependencies */

/* Indicates whether we expect mbedtls_entropy_init
 * to initialize some strong entropy source. */
#if defined(MBEDTLS_TEST_NULL_ENTROPY) ||             \
    ( !defined(MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES) && \
      ( !defined(MBEDTLS_NO_PLATFORM_ENTROPY)  ||     \
         defined(MBEDTLS_HAVEGE_C)             ||     \
         defined(MBEDTLS_ENTROPY_HARDWARE_ALT) ||     \
         defined(ENTROPY_NV_SEED) ) )
#define ENTROPY_HAVE_STRONG
#endif


/*----------------------------------------------------------------------------*/
/* Helper Functions */

/** Set the test step number for failure reports.
 *
 * Call this function to display "step NNN" in addition to the line number
 * and file name if a test fails. Typically the "step number" is the index
 * of a for loop but it can be whatever you want.
 *
 * \param step  The step number to report.
 */
void test_set_step( unsigned long step )
{
    test_info.step = step;
}

void test_fail( const char *test, int line_no, const char* filename )
{
    test_info.result = TEST_RESULT_FAILED;
    test_info.test = test;
    test_info.line_no = line_no;
    test_info.filename = filename;
}

void test_skip( const char *test, int line_no, const char* filename )
{
    test_info.result = TEST_RESULT_SKIPPED;
    test_info.test = test;
    test_info.line_no = line_no;
    test_info.filename = filename;
}

static int platform_setup()
{
    int ret = 0;
#if defined(MBEDTLS_PLATFORM_C)
    ret = mbedtls_platform_setup( &platform_ctx );
#endif /* MBEDTLS_PLATFORM_C */
    return( ret );
}

static void platform_teardown()
{
#if defined(MBEDTLS_PLATFORM_C)
    mbedtls_platform_teardown( &platform_ctx );
#endif /* MBEDTLS_PLATFORM_C */
}

#if defined(MBEDTLS_CHECK_PARAMS)
void mbedtls_param_failed( const char *failure_condition,
                           const char *file,
                           int line )
{
    /* If we are testing the callback function...  */
    if( test_info.paramfail_test_state == PARAMFAIL_TESTSTATE_PENDING )
    {
        test_info.paramfail_test_state = PARAMFAIL_TESTSTATE_CALLED;
    }
    else
    {
        /* ...else we treat this as an error */

        /* Record the location of the failure, but not as a failure yet, in case
         * it was part of the test */
        test_fail( failure_condition, line, file );
        test_info.result = TEST_RESULT_SUCCESS;

        longjmp( param_fail_jmp, 1 );
    }
}
#endif

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
static int redirect_output( FILE** out_stream, const char* path )
{
    int stdout_fd = dup( fileno( *out_stream ) );

    if( stdout_fd == -1 )
    {
        return -1;
    }

    fflush( *out_stream );
    fclose( *out_stream );
    *out_stream = fopen( path, "w" );

    if( *out_stream == NULL )
    {
        close( stdout_fd );
        return -1;
    }

    return stdout_fd;
}

static int restore_output( FILE** out_stream, int old_fd )
{
    fflush( *out_stream );
    fclose( *out_stream );

    *out_stream = fdopen( old_fd, "w" );
    if( *out_stream == NULL )
    {
        return -1;
    }

    return 0;
}

static void close_output( FILE* out_stream )
{
    fclose( out_stream );
}
#endif /* __unix__ || __APPLE__ __MACH__ */

int unhexify( unsigned char *obuf, const char *ibuf )
{
    unsigned char c, c2;
    int len = strlen( ibuf ) / 2;
    TEST_HELPER_ASSERT( strlen( ibuf ) % 2 == 0 ); /* must be even number of bytes */

    while( *ibuf != 0 )
    {
        c = *ibuf++;
        if( c >= '0' && c <= '9' )
            c -= '0';
        else if( c >= 'a' && c <= 'f' )
            c -= 'a' - 10;
        else if( c >= 'A' && c <= 'F' )
            c -= 'A' - 10;
        else
            TEST_HELPER_ASSERT( 0 );

        c2 = *ibuf++;
        if( c2 >= '0' && c2 <= '9' )
            c2 -= '0';
        else if( c2 >= 'a' && c2 <= 'f' )
            c2 -= 'a' - 10;
        else if( c2 >= 'A' && c2 <= 'F' )
            c2 -= 'A' - 10;
        else
            TEST_HELPER_ASSERT( 0 );

        *obuf++ = ( c << 4 ) | c2;
    }

    return len;
}

void hexify( unsigned char *obuf, const unsigned char *ibuf, int len )
{
    unsigned char l, h;

    while( len != 0 )
    {
        h = *ibuf / 16;
        l = *ibuf % 16;

        if( h < 10 )
            *obuf++ = '0' + h;
        else
            *obuf++ = 'a' + h - 10;

        if( l < 10 )
            *obuf++ = '0' + l;
        else
            *obuf++ = 'a' + l - 10;

        ++ibuf;
        len--;
    }
}

/**
 * Allocate and zeroize a buffer.
 *
 * If the size if zero, a pointer to a zeroized 1-byte buffer is returned.
 *
 * For convenience, dies if allocation fails.
 */
static unsigned char *zero_alloc( size_t len )
{
    void *p;
    size_t actual_len = ( len != 0 ) ? len : 1;

    p = mbedtls_calloc( 1, actual_len );
    TEST_HELPER_ASSERT( p != NULL );

    memset( p, 0x00, actual_len );

    return( p );
}

/**
 * Allocate and fill a buffer from hex data.
 *
 * The buffer is sized exactly as needed. This allows to detect buffer
 * overruns (including overreads) when running the test suite under valgrind.
 *
 * If the size if zero, a pointer to a zeroized 1-byte buffer is returned.
 *
 * For convenience, dies if allocation fails.
 */
unsigned char *unhexify_alloc( const char *ibuf, size_t *olen )
{
    unsigned char *obuf;

    *olen = strlen( ibuf ) / 2;

    if( *olen == 0 )
        return( zero_alloc( *olen ) );

    obuf = mbedtls_calloc( 1, *olen );
    TEST_HELPER_ASSERT( obuf != NULL );

    (void) unhexify( obuf, ibuf );

    return( obuf );
}

/**
 * This function just returns data from rand().
 * Although predictable and often similar on multiple
 * runs, this does not result in identical random on
 * each run. So do not use this if the results of a
 * test depend on the random data that is generated.
 *
 * rng_state shall be NULL.
 */
static int rnd_std_rand( void *rng_state, unsigned char *output, size_t len )
{
#if !defined(__OpenBSD__)
    size_t i;

    if( rng_state != NULL )
        rng_state  = NULL;

    for( i = 0; i < len; ++i )
        output[i] = rand();
#else
    if( rng_state != NULL )
        rng_state = NULL;

    arc4random_buf( output, len );
#endif /* !OpenBSD */

    return( 0 );
}

/**
 * This function only returns zeros
 *
 * rng_state shall be NULL.
 */
int rnd_zero_rand( void *rng_state, unsigned char *output, size_t len )
{
    if( rng_state != NULL )
        rng_state  = NULL;

    memset( output, 0, len );

    return( 0 );
}

typedef struct
{
    unsigned char *buf;
    size_t length;
} rnd_buf_info;

/**
 * This function returns random based on a buffer it receives.
 *
 * rng_state shall be a pointer to a rnd_buf_info structure.
 *
 * The number of bytes released from the buffer on each call to
 * the random function is specified by per_call. (Can be between
 * 1 and 4)
 *
 * After the buffer is empty it will return rand();
 */
int rnd_buffer_rand( void *rng_state, unsigned char *output, size_t len )
{
    rnd_buf_info *info = (rnd_buf_info *) rng_state;
    size_t use_len;

    if( rng_state == NULL )
        return( rnd_std_rand( NULL, output, len ) );

    use_len = len;
    if( len > info->length )
        use_len = info->length;

    if( use_len )
    {
        memcpy( output, info->buf, use_len );
        info->buf += use_len;
        info->length -= use_len;
    }

    if( len - use_len > 0 )
        return( rnd_std_rand( NULL, output + use_len, len - use_len ) );

    return( 0 );
}

/**
 * Info structure for the pseudo random function
 *
 * Key should be set at the start to a test-unique value.
 * Do not forget endianness!
 * State( v0, v1 ) should be set to zero.
 */
typedef struct
{
    uint32_t key[16];
    uint32_t v0, v1;
} rnd_pseudo_info;

/**
 * This function returns random based on a pseudo random function.
 * This means the results should be identical on all systems.
 * Pseudo random is based on the XTEA encryption algorithm to
 * generate pseudorandom.
 *
 * rng_state shall be a pointer to a rnd_pseudo_info structure.
 */
int rnd_pseudo_rand( void *rng_state, unsigned char *output, size_t len )
{
    rnd_pseudo_info *info = (rnd_pseudo_info *) rng_state;
    uint32_t i, *k, sum, delta=0x9E3779B9;
    unsigned char result[4], *out = output;

    if( rng_state == NULL )
        return( rnd_std_rand( NULL, output, len ) );

    k = info->key;

    while( len > 0 )
    {
        size_t use_len = ( len > 4 ) ? 4 : len;
        sum = 0;

        for( i = 0; i < 32; i++ )
        {
            info->v0 += ( ( ( info->v1 << 4 ) ^ ( info->v1 >> 5 ) )
                            + info->v1 ) ^ ( sum + k[sum & 3] );
            sum += delta;
            info->v1 += ( ( ( info->v0 << 4 ) ^ ( info->v0 >> 5 ) )
                            + info->v0 ) ^ ( sum + k[( sum>>11 ) & 3] );
        }

        PUT_UINT32_BE( info->v0, result, 0 );
        memcpy( out, result, use_len );
        len -= use_len;
        out += 4;
    }

    return( 0 );
}

int hexcmp( uint8_t * a, uint8_t * b, uint32_t a_len, uint32_t b_len )
{
    int ret = 0;
    uint32_t i = 0;

    if( a_len != b_len )
        return( -1 );

    for( i = 0; i < a_len; i++ )
    {
        if( a[i] != b[i] )
        {
            ret = -1;
            break;
        }
    }
    return ret;
}


#line 47 "suites/main_test.function"


/*----------------------------------------------------------------------------*/
/* Test Suite Code */


#define TEST_SUITE_ACTIVE

#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_BIGNUM_C)
#if defined(MBEDTLS_GENPRIME)
#line 2 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
#include "mbedtls/rsa.h"
#include "mbedtls/rsa_internal.h"
#include "mbedtls/md2.h"
#include "mbedtls/md4.h"
#include "mbedtls/md5.h"
#include "mbedtls/sha1.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"

#if defined(MBEDTLS_CHECK_PARAMS)
#if !defined(MBEDTLS_PARAM_FAILED_ALT)
#line 21 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_invalid_param( )
{
    mbedtls_rsa_context ctx;
    const int valid_padding = MBEDTLS_RSA_PKCS_V21;
    const int invalid_padding = 42;
    const int valid_mode = MBEDTLS_RSA_PRIVATE;
    const int invalid_mode = 42;
    unsigned char buf[42] = { 0 };
    size_t olen;

    TEST_INVALID_PARAM( mbedtls_rsa_init( NULL, valid_padding, 0 ) );
    TEST_INVALID_PARAM( mbedtls_rsa_init( &ctx, invalid_padding, 0 ) );
    TEST_VALID_PARAM( mbedtls_rsa_free( NULL ) );

    /* No more variants because only the first argument must be non-NULL. */
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_import( NULL, NULL, NULL,
                                                NULL, NULL, NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_import_raw( NULL,
                                                    NULL, 0,
                                                    NULL, 0,
                                                    NULL, 0,
                                                    NULL, 0,
                                                    NULL, 0 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_complete( NULL ) );

    /* No more variants because only the first argument must be non-NULL. */
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_export( NULL, NULL, NULL,
                                                NULL, NULL, NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_export_raw( NULL,
                                                    NULL, 0,
                                                    NULL, 0,
                                                    NULL, 0,
                                                    NULL, 0,
                                                    NULL, 0 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_export_crt( NULL, NULL, NULL, NULL ) );

    TEST_INVALID_PARAM( mbedtls_rsa_set_padding( NULL,
                                                 valid_padding, 0 ) );
    TEST_INVALID_PARAM( mbedtls_rsa_set_padding( &ctx,
                                                 invalid_padding, 0 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_gen_key( NULL, rnd_std_rand,
                                                 NULL, 0, 0 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_gen_key( &ctx, NULL,
                                                 NULL, 0, 0 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_check_pubkey( NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_check_privkey( NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_check_pub_priv( NULL, &ctx ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_check_pub_priv( &ctx, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_public( NULL, buf, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_public( &ctx, NULL, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_public( &ctx, buf, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_private( NULL, NULL, NULL,
                                                 buf, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_private( &ctx, NULL, NULL,
                                                 NULL, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_private( &ctx, NULL, NULL,
                                                 buf, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_encrypt( NULL, NULL, NULL,
                                                       valid_mode,
                                                       sizeof( buf ), buf,
                                                       buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_encrypt( &ctx, NULL, NULL,
                                                       invalid_mode,
                                                       sizeof( buf ), buf,
                                                       buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_encrypt( &ctx, NULL, NULL,
                                                       valid_mode,
                                                       sizeof( buf ), NULL,
                                                       buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_encrypt( &ctx, NULL, NULL,
                                                       valid_mode,
                                                       sizeof( buf ), buf,
                                                       NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_encrypt( NULL, NULL,
                                                           NULL,
                                                           valid_mode,
                                                           sizeof( buf ), buf,
                                                           buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_encrypt( &ctx, NULL,
                                                           NULL,
                                                           invalid_mode,
                                                           sizeof( buf ), buf,
                                                           buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_encrypt( &ctx, NULL,
                                                           NULL,
                                                           valid_mode,
                                                           sizeof( buf ), NULL,
                                                           buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_encrypt( &ctx, NULL,
                                                           NULL,
                                                           valid_mode,
                                                           sizeof( buf ), buf,
                                                           NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_encrypt( NULL, NULL, NULL,
                                                            valid_mode,
                                                            buf, sizeof( buf ),
                                                            sizeof( buf ), buf,
                                                            buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_encrypt( &ctx, NULL, NULL,
                                                            invalid_mode,
                                                            buf, sizeof( buf ),
                                                            sizeof( buf ), buf,
                                                            buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_encrypt( &ctx, NULL, NULL,
                                                            valid_mode,
                                                            NULL, sizeof( buf ),
                                                            sizeof( buf ), buf,
                                                            buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_encrypt( &ctx, NULL, NULL,
                                                            valid_mode,
                                                            buf, sizeof( buf ),
                                                            sizeof( buf ), NULL,
                                                            buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_encrypt( &ctx, NULL, NULL,
                                                            valid_mode,
                                                            buf, sizeof( buf ),
                                                            sizeof( buf ), buf,
                                                            NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_decrypt( NULL, NULL, NULL,
                                                       valid_mode, &olen,
                                                       buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_decrypt( &ctx, NULL, NULL,
                                                       invalid_mode, &olen,
                                                       buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_decrypt( &ctx, NULL, NULL,
                                                       valid_mode, NULL,
                                                       buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_decrypt( &ctx, NULL, NULL,
                                                       valid_mode, &olen,
                                                       NULL, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_decrypt( &ctx, NULL, NULL,
                                                       valid_mode, &olen,
                                                       buf, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_decrypt( NULL, NULL,
                                                           NULL,
                                                           valid_mode, &olen,
                                                           buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_decrypt( &ctx, NULL,
                                                           NULL,
                                                           invalid_mode, &olen,
                                                           buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_decrypt( &ctx, NULL,
                                                           NULL,
                                                           valid_mode, NULL,
                                                           buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_decrypt( &ctx, NULL,
                                                           NULL,
                                                           valid_mode, &olen,
                                                           NULL, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_pkcs1_v15_decrypt( &ctx, NULL,
                                                           NULL,
                                                           valid_mode, &olen,
                                                           buf, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_decrypt( NULL, NULL, NULL,
                                                            valid_mode,
                                                            buf, sizeof( buf ),
                                                            &olen,
                                                            buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_decrypt( &ctx, NULL, NULL,
                                                            invalid_mode,
                                                            buf, sizeof( buf ),
                                                            &olen,
                                                            buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_decrypt( &ctx, NULL, NULL,
                                                            valid_mode,
                                                            NULL, sizeof( buf ),
                                                            NULL,
                                                            buf, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_decrypt( &ctx, NULL, NULL,
                                                            valid_mode,
                                                            buf, sizeof( buf ),
                                                            &olen,
                                                            NULL, buf, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsaes_oaep_decrypt( &ctx, NULL, NULL,
                                                            valid_mode,
                                                            buf, sizeof( buf ),
                                                            &olen,
                                                            buf, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_sign( NULL, NULL, NULL,
                                                    valid_mode,
                                                    0, sizeof( buf ), buf,
                                                    buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_sign( &ctx, NULL, NULL,
                                                    invalid_mode,
                                                    0, sizeof( buf ), buf,
                                                    buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_sign( &ctx, NULL, NULL,
                                                    valid_mode,
                                                    0, sizeof( buf ), NULL,
                                                    buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_sign( &ctx, NULL, NULL,
                                                    valid_mode,
                                                    0, sizeof( buf ), buf,
                                                    NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_sign( &ctx, NULL, NULL,
                                                    valid_mode,
                                                    MBEDTLS_MD_SHA1,
                                                    0, NULL,
                                                    buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_sign( NULL, NULL, NULL,
                                                        valid_mode,
                                                        0, sizeof( buf ), buf,
                                                        buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_sign( &ctx, NULL, NULL,
                                                        invalid_mode,
                                                        0, sizeof( buf ), buf,
                                                        buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_sign( &ctx, NULL, NULL,
                                                        valid_mode,
                                                        0, sizeof( buf ), NULL,
                                                        buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_sign( &ctx, NULL, NULL,
                                                        valid_mode,
                                                        0, sizeof( buf ), buf,
                                                        NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_sign( &ctx, NULL, NULL,
                                                        valid_mode,
                                                        MBEDTLS_MD_SHA1,
                                                        0, NULL,
                                                        buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_sign( NULL, NULL, NULL,
                                                         valid_mode,
                                                         0, sizeof( buf ), buf,
                                                         buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_sign( &ctx, NULL, NULL,
                                                         invalid_mode,
                                                         0, sizeof( buf ), buf,
                                                         buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_sign( &ctx, NULL, NULL,
                                                         valid_mode,
                                                         0, sizeof( buf ), NULL,
                                                         buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_sign( &ctx, NULL, NULL,
                                                         valid_mode,
                                                         0, sizeof( buf ), buf,
                                                         NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_sign( &ctx, NULL, NULL,
                                                         valid_mode,
                                                         MBEDTLS_MD_SHA1,
                                                         0, NULL,
                                                         buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_verify( NULL, NULL, NULL,
                                                      valid_mode,
                                                      0, sizeof( buf ), buf,
                                                      buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_verify( &ctx, NULL, NULL,
                                                      invalid_mode,
                                                      0, sizeof( buf ), buf,
                                                      buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_verify( &ctx, NULL, NULL,
                                                      valid_mode,
                                                      0, sizeof( buf ), NULL,
                                                      buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_verify( &ctx, NULL, NULL,
                                                      valid_mode,
                                                      0, sizeof( buf ), buf,
                                                      NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_pkcs1_verify( &ctx, NULL, NULL,
                                                      valid_mode,
                                                      MBEDTLS_MD_SHA1, 0, NULL,
                                                      buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_verify( NULL, NULL,
                                                          NULL,
                                                          valid_mode,
                                                          0, sizeof( buf ), buf,
                                                          buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_verify( &ctx, NULL,
                                                          NULL,
                                                          invalid_mode,
                                                          0, sizeof( buf ), buf,
                                                          buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_verify( &ctx, NULL,
                                                          NULL,
                                                          valid_mode,
                                                          0, sizeof( buf ),
                                                          NULL, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_verify( &ctx, NULL,
                                                          NULL,
                                                          valid_mode,
                                                          0, sizeof( buf ), buf,
                                                          NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pkcs1_v15_verify( &ctx, NULL,
                                                          NULL,
                                                          valid_mode,
                                                          MBEDTLS_MD_SHA1,
                                                          0, NULL,
                                                          buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify( NULL, NULL, NULL,
                                                           valid_mode,
                                                           0, sizeof( buf ),
                                                           buf, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify( &ctx, NULL, NULL,
                                                           invalid_mode,
                                                           0, sizeof( buf ),
                                                           buf, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify( &ctx, NULL, NULL,
                                                           valid_mode,
                                                           0, sizeof( buf ),
                                                           NULL, buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify( &ctx, NULL, NULL,
                                                           valid_mode,
                                                           0, sizeof( buf ),
                                                           buf, NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify( &ctx, NULL, NULL,
                                                           valid_mode,
                                                           MBEDTLS_MD_SHA1,
                                                           0, NULL,
                                                           buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify_ext( NULL, NULL, NULL,
                                                               valid_mode,
                                                               0, sizeof( buf ),
                                                               buf,
                                                               0, 0,
                                                               buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify_ext( &ctx, NULL, NULL,
                                                               invalid_mode,
                                                               0, sizeof( buf ),
                                                               buf,
                                                               0, 0,
                                                               buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify_ext( &ctx, NULL, NULL,
                                                               valid_mode,
                                                               0, sizeof( buf ),
                                                               NULL, 0, 0,
                                                               buf ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify_ext( &ctx, NULL, NULL,
                                                               valid_mode,
                                                               0, sizeof( buf ),
                                                               buf, 0, 0,
                                                               NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_rsassa_pss_verify_ext( &ctx, NULL, NULL,
                                                               valid_mode,
                                                               MBEDTLS_MD_SHA1,
                                                               0, NULL,
                                                               0, 0,
                                                               buf ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_copy( NULL, &ctx ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_RSA_BAD_INPUT_DATA,
                            mbedtls_rsa_copy( &ctx, NULL ) );

exit:
    return;
}

void test_rsa_invalid_param_wrapper( void ** params )
{
    (void)params;

    test_rsa_invalid_param(  );
}
#endif /* !MBEDTLS_PARAM_FAILED_ALT */
#endif /* MBEDTLS_CHECK_PARAMS */
#line 469 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_pkcs1_sign( data_t * message_str, int padding_mode,
                             int digest, int mod, int radix_P, char * input_P,
                             int radix_Q, char * input_Q, int radix_N,
                             char * input_N, int radix_E, char * input_E,
                             data_t * result_hex_str, int result )
{
    unsigned char hash_result[MBEDTLS_MD_MAX_SIZE];
    unsigned char output[256];
    mbedtls_rsa_context ctx;
    mbedtls_mpi N, P, Q, E;
    rnd_pseudo_info rnd_info;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &P );
    mbedtls_mpi_init( &Q ); mbedtls_mpi_init( &E );
    mbedtls_rsa_init( &ctx, padding_mode, 0 );

    memset( hash_result, 0x00, sizeof( hash_result ) );
    memset( output, 0x00, sizeof( output ) );
    memset( &rnd_info, 0, sizeof( rnd_pseudo_info ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, &P, &Q, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == 0 );
    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == 0 );


    if( mbedtls_md_info_from_type( digest ) != NULL )
        TEST_ASSERT( mbedtls_md( mbedtls_md_info_from_type( digest ), message_str->x, message_str->len, hash_result ) == 0 );

    TEST_ASSERT( mbedtls_rsa_pkcs1_sign( &ctx, &rnd_pseudo_rand, &rnd_info,
                                         MBEDTLS_RSA_PRIVATE, digest, 0,
                                         hash_result, output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &P );
    mbedtls_mpi_free( &Q ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_pkcs1_sign_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data13 = {(uint8_t *) params[13], *( (uint32_t *) params[14] )};

    test_mbedtls_rsa_pkcs1_sign( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), (char *) params[6], *( (int *) params[7] ), (char *) params[8], *( (int *) params[9] ), (char *) params[10], *( (int *) params[11] ), (char *) params[12], &data13, *( (int *) params[15] ) );
}
#line 520 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_pkcs1_verify( data_t * message_str, int padding_mode,
                               int digest, int mod, int radix_N,
                               char * input_N, int radix_E, char * input_E,
                               data_t * result_str, int result )
{
    unsigned char hash_result[MBEDTLS_MD_MAX_SIZE];
    mbedtls_rsa_context ctx;

    mbedtls_mpi N, E;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &E );
    mbedtls_rsa_init( &ctx, padding_mode, 0 );
    memset( hash_result, 0x00, sizeof( hash_result ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, NULL, NULL, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == 0 );


    if( mbedtls_md_info_from_type( digest ) != NULL )
        TEST_ASSERT( mbedtls_md( mbedtls_md_info_from_type( digest ), message_str->x, message_str->len, hash_result ) == 0 );

    TEST_ASSERT( mbedtls_rsa_pkcs1_verify( &ctx, NULL, NULL, MBEDTLS_RSA_PUBLIC, digest, 0, hash_result, result_str->x ) == result );

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_pkcs1_verify_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data9 = {(uint8_t *) params[9], *( (uint32_t *) params[10] )};

    test_mbedtls_rsa_pkcs1_verify( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), (char *) params[6], *( (int *) params[7] ), (char *) params[8], &data9, *( (int *) params[11] ) );
}
#line 554 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_pkcs1_sign_raw( data_t * hash_result,
                         int padding_mode, int mod, int radix_P,
                         char * input_P, int radix_Q, char * input_Q,
                         int radix_N, char * input_N, int radix_E,
                         char * input_E, data_t * result_hex_str )
{
    unsigned char output[256];
    mbedtls_rsa_context ctx;
    mbedtls_mpi N, P, Q, E;
    rnd_pseudo_info rnd_info;

    mbedtls_rsa_init( &ctx, padding_mode, 0 );
    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &P );
    mbedtls_mpi_init( &Q ); mbedtls_mpi_init( &E );

    memset( output, 0x00, sizeof( output ) );
    memset( &rnd_info, 0, sizeof( rnd_pseudo_info ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, &P, &Q, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == 0 );
    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == 0 );


    TEST_ASSERT( mbedtls_rsa_pkcs1_sign( &ctx, &rnd_pseudo_rand, &rnd_info,
                                         MBEDTLS_RSA_PRIVATE, MBEDTLS_MD_NONE,
                                         hash_result->len, hash_result->x,
                                         output ) == 0 );


    TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );

#if defined(MBEDTLS_PKCS1_V15)
    /* For PKCS#1 v1.5, there is an alternative way to generate signatures */
    if( padding_mode == MBEDTLS_RSA_PKCS_V15 )
    {
        int res;
        memset( output, 0x00, sizeof( output) );

        res = mbedtls_rsa_rsaes_pkcs1_v15_encrypt( &ctx,
                    &rnd_pseudo_rand, &rnd_info, MBEDTLS_RSA_PRIVATE,
                    hash_result->len, hash_result->x, output );

#if !defined(MBEDTLS_RSA_ALT)
        TEST_ASSERT( res == 0 );
#else
        TEST_ASSERT( ( res == 0 ) ||
                     ( res == MBEDTLS_ERR_RSA_UNSUPPORTED_OPERATION ) );
#endif

        if( res == 0 )
        {
            TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
        }
    }
#endif /* MBEDTLS_PKCS1_V15 */

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &P );
    mbedtls_mpi_free( &Q ); mbedtls_mpi_free( &E );

    mbedtls_rsa_free( &ctx );
}

void test_rsa_pkcs1_sign_raw_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data12 = {(uint8_t *) params[12], *( (uint32_t *) params[13] )};

    test_rsa_pkcs1_sign_raw( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ), (char *) params[11], &data12 );
}
#line 625 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_pkcs1_verify_raw( data_t * hash_result,
                           int padding_mode, int mod, int radix_N,
                           char * input_N, int radix_E, char * input_E,
                           data_t * result_str, int correct )
{
    unsigned char output[256];
    mbedtls_rsa_context ctx;

    mbedtls_mpi N, E;
    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &E );

    mbedtls_rsa_init( &ctx, padding_mode, 0 );
    memset( output, 0x00, sizeof( output ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, NULL, NULL, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == 0 );


    TEST_ASSERT( mbedtls_rsa_pkcs1_verify( &ctx, NULL, NULL, MBEDTLS_RSA_PUBLIC, MBEDTLS_MD_NONE, hash_result->len, hash_result->x, result_str->x ) == correct );

#if defined(MBEDTLS_PKCS1_V15)
    /* For PKCS#1 v1.5, there is an alternative way to verify signatures */
    if( padding_mode == MBEDTLS_RSA_PKCS_V15 )
    {
        int res;
        int ok;
        size_t olen;

        res = mbedtls_rsa_rsaes_pkcs1_v15_decrypt( &ctx,
                    NULL, NULL, MBEDTLS_RSA_PUBLIC,
                    &olen, result_str->x, output, sizeof( output ) );

#if !defined(MBEDTLS_RSA_ALT)
        TEST_ASSERT( res == 0 );
#else
        TEST_ASSERT( ( res == 0 ) ||
                     ( res == MBEDTLS_ERR_RSA_UNSUPPORTED_OPERATION ) );
#endif

        if( res == 0 )
        {
            ok = olen == hash_result->len && memcmp( output, hash_result->x, olen ) == 0;
            if( correct == 0 )
                TEST_ASSERT( ok == 1 );
            else
                TEST_ASSERT( ok == 0 );
        }
    }
#endif /* MBEDTLS_PKCS1_V15 */

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_rsa_pkcs1_verify_raw_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_rsa_pkcs1_verify_raw( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], &data8, *( (int *) params[10] ) );
}
#line 686 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_pkcs1_encrypt( data_t * message_str, int padding_mode,
                                int mod, int radix_N, char * input_N,
                                int radix_E, char * input_E,
                                data_t * result_hex_str, int result )
{
    unsigned char output[256];
    mbedtls_rsa_context ctx;
    rnd_pseudo_info rnd_info;

    mbedtls_mpi N, E;
    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &E );

    memset( &rnd_info, 0, sizeof( rnd_pseudo_info ) );

    mbedtls_rsa_init( &ctx, padding_mode, 0 );
    memset( output, 0x00, sizeof( output ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, NULL, NULL, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == 0 );


    TEST_ASSERT( mbedtls_rsa_pkcs1_encrypt( &ctx, &rnd_pseudo_rand, &rnd_info,
                                            MBEDTLS_RSA_PUBLIC, message_str->len,
                                            message_str->x, output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_pkcs1_encrypt_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_mbedtls_rsa_pkcs1_encrypt( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], &data8, *( (int *) params[10] ) );
}
#line 727 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_pkcs1_encrypt_bad_rng( data_t * message_str, int padding_mode,
                                int mod, int radix_N, char * input_N,
                                int radix_E, char * input_E,
                                data_t * result_hex_str, int result )
{
    unsigned char output[256];
    mbedtls_rsa_context ctx;

    mbedtls_mpi N, E;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &E );
    mbedtls_rsa_init( &ctx, padding_mode, 0 );
    memset( output, 0x00, sizeof( output ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, NULL, NULL, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == 0 );


    TEST_ASSERT( mbedtls_rsa_pkcs1_encrypt( &ctx, &rnd_zero_rand, NULL,
                                            MBEDTLS_RSA_PUBLIC, message_str->len,
                                            message_str->x, output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_rsa_pkcs1_encrypt_bad_rng_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_rsa_pkcs1_encrypt_bad_rng( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], &data8, *( (int *) params[10] ) );
}
#line 765 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_pkcs1_decrypt( data_t * message_str, int padding_mode,
                                int mod, int radix_P, char * input_P,
                                int radix_Q, char * input_Q, int radix_N,
                                char * input_N, int radix_E, char * input_E,
                                int max_output, data_t * result_hex_str,
                                int result )
{
    unsigned char output[32];
    mbedtls_rsa_context ctx;
    size_t output_len;
    rnd_pseudo_info rnd_info;
    mbedtls_mpi N, P, Q, E;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &P );
    mbedtls_mpi_init( &Q ); mbedtls_mpi_init( &E );

    mbedtls_rsa_init( &ctx, padding_mode, 0 );

    memset( output, 0x00, sizeof( output ) );
    memset( &rnd_info, 0, sizeof( rnd_pseudo_info ) );


    TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, &P, &Q, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == 0 );
    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == 0 );

    output_len = 0;

    TEST_ASSERT( mbedtls_rsa_pkcs1_decrypt( &ctx, rnd_pseudo_rand, &rnd_info, MBEDTLS_RSA_PRIVATE, &output_len, message_str->x, output, max_output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, output_len, result_hex_str->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &P );
    mbedtls_mpi_free( &Q ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_pkcs1_decrypt_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data13 = {(uint8_t *) params[13], *( (uint32_t *) params[14] )};

    test_mbedtls_rsa_pkcs1_decrypt( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ), (char *) params[11], *( (int *) params[12] ), &data13, *( (int *) params[15] ) );
}
#line 814 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_public( data_t * message_str, int mod, int radix_N,
                         char * input_N, int radix_E, char * input_E,
                         data_t * result_hex_str, int result )
{
    unsigned char output[256];
    mbedtls_rsa_context ctx, ctx2; /* Also test mbedtls_rsa_copy() while at it */

    mbedtls_mpi N, E;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &E );
    mbedtls_rsa_init( &ctx, MBEDTLS_RSA_PKCS_V15, 0 );
    mbedtls_rsa_init( &ctx2, MBEDTLS_RSA_PKCS_V15, 0 );
    memset( output, 0x00, sizeof( output ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, NULL, NULL, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == 0 );


    TEST_ASSERT( mbedtls_rsa_public( &ctx, message_str->x, output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
    }

    /* And now with the copy */
    TEST_ASSERT( mbedtls_rsa_copy( &ctx2, &ctx ) == 0 );
    /* clear the original to be sure */
    mbedtls_rsa_free( &ctx );

    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx2 ) == 0 );

    memset( output, 0x00, sizeof( output ) );
    TEST_ASSERT( mbedtls_rsa_public( &ctx2, message_str->x, output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
    mbedtls_rsa_free( &ctx2 );
}

void test_mbedtls_rsa_public_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data7 = {(uint8_t *) params[7], *( (uint32_t *) params[8] )};

    test_mbedtls_rsa_public( &data0, *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4], *( (int *) params[5] ), (char *) params[6], &data7, *( (int *) params[9] ) );
}
#line 866 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_private( data_t * message_str, int mod, int radix_P,
                          char * input_P, int radix_Q, char * input_Q,
                          int radix_N, char * input_N, int radix_E,
                          char * input_E, data_t * result_hex_str,
                          int result )
{
    unsigned char output[256];
    mbedtls_rsa_context ctx, ctx2; /* Also test mbedtls_rsa_copy() while at it */
    mbedtls_mpi N, P, Q, E;
    rnd_pseudo_info rnd_info;
    int i;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &P );
    mbedtls_mpi_init( &Q ); mbedtls_mpi_init( &E );
    mbedtls_rsa_init( &ctx, MBEDTLS_RSA_PKCS_V15, 0 );
    mbedtls_rsa_init( &ctx2, MBEDTLS_RSA_PKCS_V15, 0 );

    memset( &rnd_info, 0, sizeof( rnd_pseudo_info ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, &P, &Q, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_get_len( &ctx ) == (size_t) ( mod / 8 ) );
    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == 0 );
    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == 0 );


    /* repeat three times to test updating of blinding values */
    for( i = 0; i < 3; i++ )
    {
        memset( output, 0x00, sizeof( output ) );
        TEST_ASSERT( mbedtls_rsa_private( &ctx, rnd_pseudo_rand, &rnd_info,
                                  message_str->x, output ) == result );
        if( result == 0 )
        {

            TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx.len, result_hex_str->len ) == 0 );
        }
    }

    /* And now one more time with the copy */
    TEST_ASSERT( mbedtls_rsa_copy( &ctx2, &ctx ) == 0 );
    /* clear the original to be sure */
    mbedtls_rsa_free( &ctx );

    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx2 ) == 0 );

    memset( output, 0x00, sizeof( output ) );
    TEST_ASSERT( mbedtls_rsa_private( &ctx2, rnd_pseudo_rand, &rnd_info,
                              message_str->x, output ) == result );
    if( result == 0 )
    {

        TEST_ASSERT( hexcmp( output, result_hex_str->x, ctx2.len, result_hex_str->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &P );
    mbedtls_mpi_free( &Q ); mbedtls_mpi_free( &E );

    mbedtls_rsa_free( &ctx ); mbedtls_rsa_free( &ctx2 );
}

void test_mbedtls_rsa_private_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data11 = {(uint8_t *) params[11], *( (uint32_t *) params[12] )};

    test_mbedtls_rsa_private( &data0, *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4], *( (int *) params[5] ), (char *) params[6], *( (int *) params[7] ), (char *) params[8], *( (int *) params[9] ), (char *) params[10], &data11, *( (int *) params[13] ) );
}
#line 934 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_check_privkey_null(  )
{
    mbedtls_rsa_context ctx;
    memset( &ctx, 0x00, sizeof( mbedtls_rsa_context ) );

    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == MBEDTLS_ERR_RSA_KEY_CHECK_FAILED );
exit:
    ;
}

void test_rsa_check_privkey_null_wrapper( void ** params )
{
    (void)params;

    test_rsa_check_privkey_null(  );
}
#line 944 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_check_pubkey( int radix_N, char * input_N, int radix_E,
                               char * input_E, int result )
{
    mbedtls_rsa_context ctx;
    mbedtls_mpi N, E;

    mbedtls_mpi_init( &N ); mbedtls_mpi_init( &E );
    mbedtls_rsa_init( &ctx, MBEDTLS_RSA_PKCS_V15, 0 );

    if( strlen( input_N ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    }
    if( strlen( input_E ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );
    }

    TEST_ASSERT( mbedtls_rsa_import( &ctx, &N, NULL, NULL, NULL, &E ) == 0 );
    TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == result );

exit:
    mbedtls_mpi_free( &N ); mbedtls_mpi_free( &E );
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_check_pubkey_wrapper( void ** params )
{

    test_mbedtls_rsa_check_pubkey( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ) );
}
#line 972 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_check_privkey( int mod, int radix_P, char * input_P,
                                int radix_Q, char * input_Q, int radix_N,
                                char * input_N, int radix_E, char * input_E,
                                int radix_D, char * input_D, int radix_DP,
                                char * input_DP, int radix_DQ,
                                char * input_DQ, int radix_QP,
                                char * input_QP, int result )
{
    mbedtls_rsa_context ctx;

    mbedtls_rsa_init( &ctx, MBEDTLS_RSA_PKCS_V15, 0 );

    ctx.len = mod / 8;
    if( strlen( input_P ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.P, radix_P, input_P ) == 0 );
    }
    if( strlen( input_Q ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.Q, radix_Q, input_Q ) == 0 );
    }
    if( strlen( input_N ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.N, radix_N, input_N ) == 0 );
    }
    if( strlen( input_E ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.E, radix_E, input_E ) == 0 );
    }
    if( strlen( input_D ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.D, radix_D, input_D ) == 0 );
    }
#if !defined(MBEDTLS_RSA_NO_CRT)
    if( strlen( input_DP ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.DP, radix_DP, input_DP ) == 0 );
    }
    if( strlen( input_DQ ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.DQ, radix_DQ, input_DQ ) == 0 );
    }
    if( strlen( input_QP ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &ctx.QP, radix_QP, input_QP ) == 0 );
    }
#else
    ((void) radix_DP); ((void) input_DP);
    ((void) radix_DQ); ((void) input_DQ);
    ((void) radix_QP); ((void) input_QP);
#endif

    TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == result );

exit:
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_check_privkey_wrapper( void ** params )
{

    test_mbedtls_rsa_check_privkey( *( (int *) params[0] ), *( (int *) params[1] ), (char *) params[2], *( (int *) params[3] ), (char *) params[4], *( (int *) params[5] ), (char *) params[6], *( (int *) params[7] ), (char *) params[8], *( (int *) params[9] ), (char *) params[10], *( (int *) params[11] ), (char *) params[12], *( (int *) params[13] ), (char *) params[14], *( (int *) params[15] ), (char *) params[16], *( (int *) params[17] ) );
}
#line 1032 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_check_pubpriv( int mod, int radix_Npub, char * input_Npub,
                        int radix_Epub, char * input_Epub, int radix_P,
                        char * input_P, int radix_Q, char * input_Q,
                        int radix_N, char * input_N, int radix_E,
                        char * input_E, int radix_D, char * input_D,
                        int radix_DP, char * input_DP, int radix_DQ,
                        char * input_DQ, int radix_QP, char * input_QP,
                        int result )
{
    mbedtls_rsa_context pub, prv;

    mbedtls_rsa_init( &pub, MBEDTLS_RSA_PKCS_V15, 0 );
    mbedtls_rsa_init( &prv, MBEDTLS_RSA_PKCS_V15, 0 );

    pub.len = mod / 8;
    prv.len = mod / 8;

    if( strlen( input_Npub ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &pub.N, radix_Npub, input_Npub ) == 0 );
    }
    if( strlen( input_Epub ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &pub.E, radix_Epub, input_Epub ) == 0 );
    }

    if( strlen( input_P ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.P, radix_P, input_P ) == 0 );
    }
    if( strlen( input_Q ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.Q, radix_Q, input_Q ) == 0 );
    }
    if( strlen( input_N ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.N, radix_N, input_N ) == 0 );
    }
    if( strlen( input_E ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.E, radix_E, input_E ) == 0 );
    }
    if( strlen( input_D ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.D, radix_D, input_D ) == 0 );
    }
#if !defined(MBEDTLS_RSA_NO_CRT)
    if( strlen( input_DP ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.DP, radix_DP, input_DP ) == 0 );
    }
    if( strlen( input_DQ ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.DQ, radix_DQ, input_DQ ) == 0 );
    }
    if( strlen( input_QP ) )
    {
        TEST_ASSERT( mbedtls_mpi_read_string( &prv.QP, radix_QP, input_QP ) == 0 );
    }
#else
    ((void) radix_DP); ((void) input_DP);
    ((void) radix_DQ); ((void) input_DQ);
    ((void) radix_QP); ((void) input_QP);
#endif

    TEST_ASSERT( mbedtls_rsa_check_pub_priv( &pub, &prv ) == result );

exit:
    mbedtls_rsa_free( &pub );
    mbedtls_rsa_free( &prv );
}

void test_rsa_check_pubpriv_wrapper( void ** params )
{

    test_rsa_check_pubpriv( *( (int *) params[0] ), *( (int *) params[1] ), (char *) params[2], *( (int *) params[3] ), (char *) params[4], *( (int *) params[5] ), (char *) params[6], *( (int *) params[7] ), (char *) params[8], *( (int *) params[9] ), (char *) params[10], *( (int *) params[11] ), (char *) params[12], *( (int *) params[13] ), (char *) params[14], *( (int *) params[15] ), (char *) params[16], *( (int *) params[17] ), (char *) params[18], *( (int *) params[19] ), (char *) params[20], *( (int *) params[21] ) );
}
#if defined(MBEDTLS_CTR_DRBG_C)
#if defined(MBEDTLS_ENTROPY_C)
#if defined(ENTROPY_HAVE_STRONG)
#line 1106 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_gen_key( int nrbits, int exponent, int result)
{
    mbedtls_rsa_context ctx;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    const char *pers = "test_suite_rsa";

    mbedtls_ctr_drbg_init( &ctr_drbg );
    mbedtls_entropy_init( &entropy );
    mbedtls_rsa_init ( &ctx, 0, 0 );

    TEST_ASSERT( mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func,
                                        &entropy, (const unsigned char *) pers,
                                        strlen( pers ) ) == 0 );

    TEST_ASSERT( mbedtls_rsa_gen_key( &ctx, mbedtls_ctr_drbg_random, &ctr_drbg, nrbits, exponent ) == result );
    if( result == 0 )
    {
        TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == 0 );
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &ctx.P, &ctx.Q ) > 0 );
    }

exit:
    mbedtls_rsa_free( &ctx );
    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );
}

void test_mbedtls_rsa_gen_key_wrapper( void ** params )
{

    test_mbedtls_rsa_gen_key( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* ENTROPY_HAVE_STRONG */
#endif /* MBEDTLS_ENTROPY_C */
#endif /* MBEDTLS_CTR_DRBG_C */
#if defined(MBEDTLS_CTR_DRBG_C)
#if defined(MBEDTLS_ENTROPY_C)
#line 1136 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_deduce_primes( int radix_N, char *input_N,
                                int radix_D, char *input_D,
                                int radix_E, char *input_E,
                                int radix_P, char *output_P,
                                int radix_Q, char *output_Q,
                                int corrupt, int result )
{
    mbedtls_mpi N, P, Pp, Q, Qp, D, E;

    mbedtls_mpi_init( &N );
    mbedtls_mpi_init( &P );  mbedtls_mpi_init( &Q  );
    mbedtls_mpi_init( &Pp ); mbedtls_mpi_init( &Qp );
    mbedtls_mpi_init( &D ); mbedtls_mpi_init( &E );

    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &D, radix_D, input_D ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Qp, radix_P, output_P ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Pp, radix_Q, output_Q ) == 0 );

    if( corrupt )
        TEST_ASSERT( mbedtls_mpi_add_int( &D, &D, 2 ) == 0 );

    /* Try to deduce P, Q from N, D, E only. */
    TEST_ASSERT( mbedtls_rsa_deduce_primes( &N, &D, &E, &P, &Q ) == result );

    if( !corrupt )
    {
        /* Check if (P,Q) = (Pp, Qp) or (P,Q) = (Qp, Pp) */
        TEST_ASSERT( ( mbedtls_mpi_cmp_mpi( &P, &Pp ) == 0 && mbedtls_mpi_cmp_mpi( &Q, &Qp ) == 0 ) ||
                     ( mbedtls_mpi_cmp_mpi( &P, &Qp ) == 0 && mbedtls_mpi_cmp_mpi( &Q, &Pp ) == 0 ) );
    }

exit:
    mbedtls_mpi_free( &N );
    mbedtls_mpi_free( &P  ); mbedtls_mpi_free( &Q  );
    mbedtls_mpi_free( &Pp ); mbedtls_mpi_free( &Qp );
    mbedtls_mpi_free( &D ); mbedtls_mpi_free( &E );
}

void test_mbedtls_rsa_deduce_primes_wrapper( void ** params )
{

    test_mbedtls_rsa_deduce_primes( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ), *( (int *) params[11] ) );
}
#endif /* MBEDTLS_ENTROPY_C */
#endif /* MBEDTLS_CTR_DRBG_C */
#line 1178 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_deduce_private_exponent( int radix_P, char *input_P,
                                          int radix_Q, char *input_Q,
                                          int radix_E, char *input_E,
                                          int radix_D, char *output_D,
                                          int corrupt, int result )
{
    mbedtls_mpi P, Q, D, Dp, E, R, Rp;

    mbedtls_mpi_init( &P ); mbedtls_mpi_init( &Q );
    mbedtls_mpi_init( &D ); mbedtls_mpi_init( &Dp );
    mbedtls_mpi_init( &E );
    mbedtls_mpi_init( &R ); mbedtls_mpi_init( &Rp );

    TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Dp, radix_D, output_D ) == 0 );

    if( corrupt )
    {
        /* Make E even */
        TEST_ASSERT( mbedtls_mpi_set_bit( &E, 0, 0 ) == 0 );
    }

    /* Try to deduce D from N, P, Q, E. */
    TEST_ASSERT( mbedtls_rsa_deduce_private_exponent( &P, &Q,
                                                      &E, &D ) == result );

    if( !corrupt )
    {
        /*
         * Check that D and Dp agree modulo LCM(P-1, Q-1).
         */

        /* Replace P,Q by P-1, Q-1 */
        TEST_ASSERT( mbedtls_mpi_sub_int( &P, &P, 1 ) == 0 );
        TEST_ASSERT( mbedtls_mpi_sub_int( &Q, &Q, 1 ) == 0 );

        /* Check D == Dp modulo P-1 */
        TEST_ASSERT( mbedtls_mpi_mod_mpi( &R,  &D,  &P ) == 0 );
        TEST_ASSERT( mbedtls_mpi_mod_mpi( &Rp, &Dp, &P ) == 0 );
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &R,  &Rp )     == 0 );

        /* Check D == Dp modulo Q-1 */
        TEST_ASSERT( mbedtls_mpi_mod_mpi( &R,  &D,  &Q ) == 0 );
        TEST_ASSERT( mbedtls_mpi_mod_mpi( &Rp, &Dp, &Q ) == 0 );
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &R,  &Rp )     == 0 );
    }

exit:

    mbedtls_mpi_free( &P ); mbedtls_mpi_free( &Q  );
    mbedtls_mpi_free( &D ); mbedtls_mpi_free( &Dp );
    mbedtls_mpi_free( &E );
    mbedtls_mpi_free( &R ); mbedtls_mpi_free( &Rp );
}

void test_mbedtls_rsa_deduce_private_exponent_wrapper( void ** params )
{

    test_mbedtls_rsa_deduce_private_exponent( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), *( (int *) params[9] ) );
}
#if defined(MBEDTLS_CTR_DRBG_C)
#if defined(MBEDTLS_ENTROPY_C)
#if defined(ENTROPY_HAVE_STRONG)
#line 1237 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_import( int radix_N, char *input_N,
                         int radix_P, char *input_P,
                         int radix_Q, char *input_Q,
                         int radix_D, char *input_D,
                         int radix_E, char *input_E,
                         int successive,
                         int is_priv,
                         int res_check,
                         int res_complete )
{
    mbedtls_mpi N, P, Q, D, E;
    mbedtls_rsa_context ctx;

    /* Buffers used for encryption-decryption test */
    unsigned char *buf_orig = NULL;
    unsigned char *buf_enc  = NULL;
    unsigned char *buf_dec  = NULL;

    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    const char *pers = "test_suite_rsa";

    const int have_N = ( strlen( input_N ) > 0 );
    const int have_P = ( strlen( input_P ) > 0 );
    const int have_Q = ( strlen( input_Q ) > 0 );
    const int have_D = ( strlen( input_D ) > 0 );
    const int have_E = ( strlen( input_E ) > 0 );

    mbedtls_ctr_drbg_init( &ctr_drbg );
    mbedtls_entropy_init( &entropy );
    mbedtls_rsa_init( &ctx, 0, 0 );

    mbedtls_mpi_init( &N );
    mbedtls_mpi_init( &P ); mbedtls_mpi_init( &Q );
    mbedtls_mpi_init( &D ); mbedtls_mpi_init( &E );

    TEST_ASSERT( mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func, &entropy,
                                (const unsigned char *) pers, strlen( pers ) ) == 0 );

    if( have_N )
        TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );

    if( have_P )
        TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );

    if( have_Q )
        TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );

    if( have_D )
        TEST_ASSERT( mbedtls_mpi_read_string( &D, radix_D, input_D ) == 0 );

    if( have_E )
        TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    if( !successive )
    {
        TEST_ASSERT( mbedtls_rsa_import( &ctx,
                             have_N ? &N : NULL,
                             have_P ? &P : NULL,
                             have_Q ? &Q : NULL,
                             have_D ? &D : NULL,
                             have_E ? &E : NULL ) == 0 );
    }
    else
    {
        /* Import N, P, Q, D, E separately.
         * This should make no functional difference. */

        TEST_ASSERT( mbedtls_rsa_import( &ctx,
                               have_N ? &N : NULL,
                               NULL, NULL, NULL, NULL ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import( &ctx,
                               NULL,
                               have_P ? &P : NULL,
                               NULL, NULL, NULL ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import( &ctx,
                               NULL, NULL,
                               have_Q ? &Q : NULL,
                               NULL, NULL ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import( &ctx,
                               NULL, NULL, NULL,
                               have_D ? &D : NULL,
                               NULL ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import( &ctx,
                               NULL, NULL, NULL, NULL,
                               have_E ? &E : NULL ) == 0 );
    }

    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == res_complete );

    /* On expected success, perform some public and private
     * key operations to check if the key is working properly. */
    if( res_complete == 0 )
    {
        if( is_priv )
            TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == res_check );
        else
            TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == res_check );

        if( res_check != 0 )
            goto exit;

        buf_orig = mbedtls_calloc( 1, mbedtls_rsa_get_len( &ctx ) );
        buf_enc  = mbedtls_calloc( 1, mbedtls_rsa_get_len( &ctx ) );
        buf_dec  = mbedtls_calloc( 1, mbedtls_rsa_get_len( &ctx ) );
        if( buf_orig == NULL || buf_enc == NULL || buf_dec == NULL )
            goto exit;

        TEST_ASSERT( mbedtls_ctr_drbg_random( &ctr_drbg,
                              buf_orig, mbedtls_rsa_get_len( &ctx ) ) == 0 );

        /* Make sure the number we're generating is smaller than the modulus */
        buf_orig[0] = 0x00;

        TEST_ASSERT( mbedtls_rsa_public( &ctx, buf_orig, buf_enc ) == 0 );

        if( is_priv )
        {
            TEST_ASSERT( mbedtls_rsa_private( &ctx, mbedtls_ctr_drbg_random,
                                              &ctr_drbg, buf_enc,
                                              buf_dec ) == 0 );

            TEST_ASSERT( memcmp( buf_orig, buf_dec,
                                 mbedtls_rsa_get_len( &ctx ) ) == 0 );
        }
    }

exit:

    mbedtls_free( buf_orig );
    mbedtls_free( buf_enc  );
    mbedtls_free( buf_dec  );

    mbedtls_rsa_free( &ctx );

    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );

    mbedtls_mpi_free( &N );
    mbedtls_mpi_free( &P ); mbedtls_mpi_free( &Q );
    mbedtls_mpi_free( &D ); mbedtls_mpi_free( &E );
}

void test_mbedtls_rsa_import_wrapper( void ** params )
{

    test_mbedtls_rsa_import( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ), *( (int *) params[11] ), *( (int *) params[12] ), *( (int *) params[13] ) );
}
#endif /* ENTROPY_HAVE_STRONG */
#endif /* MBEDTLS_ENTROPY_C */
#endif /* MBEDTLS_CTR_DRBG_C */
#line 1386 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_export( int radix_N, char *input_N,
                         int radix_P, char *input_P,
                         int radix_Q, char *input_Q,
                         int radix_D, char *input_D,
                         int radix_E, char *input_E,
                         int is_priv,
                         int successive )
{
    /* Original MPI's with which we set up the RSA context */
    mbedtls_mpi N, P, Q, D, E;

    /* Exported MPI's */
    mbedtls_mpi Ne, Pe, Qe, De, Ee;

    const int have_N = ( strlen( input_N ) > 0 );
    const int have_P = ( strlen( input_P ) > 0 );
    const int have_Q = ( strlen( input_Q ) > 0 );
    const int have_D = ( strlen( input_D ) > 0 );
    const int have_E = ( strlen( input_E ) > 0 );

    mbedtls_rsa_context ctx;

    mbedtls_rsa_init( &ctx, 0, 0 );

    mbedtls_mpi_init( &N );
    mbedtls_mpi_init( &P ); mbedtls_mpi_init( &Q );
    mbedtls_mpi_init( &D ); mbedtls_mpi_init( &E );

    mbedtls_mpi_init( &Ne );
    mbedtls_mpi_init( &Pe ); mbedtls_mpi_init( &Qe );
    mbedtls_mpi_init( &De ); mbedtls_mpi_init( &Ee );

    /* Setup RSA context */

    if( have_N )
        TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );

    if( have_P )
        TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );

    if( have_Q )
        TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );

    if( have_D )
        TEST_ASSERT( mbedtls_mpi_read_string( &D, radix_D, input_D ) == 0 );

    if( have_E )
        TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_import( &ctx,
                                     strlen( input_N ) ? &N : NULL,
                                     strlen( input_P ) ? &P : NULL,
                                     strlen( input_Q ) ? &Q : NULL,
                                     strlen( input_D ) ? &D : NULL,
                                     strlen( input_E ) ? &E : NULL ) == 0 );

    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == 0 );

    /*
     * Export parameters and compare to original ones.
     */

    /* N and E must always be present. */
    if( !successive )
    {
        TEST_ASSERT( mbedtls_rsa_export( &ctx, &Ne, NULL, NULL, NULL, &Ee ) == 0 );
    }
    else
    {
        TEST_ASSERT( mbedtls_rsa_export( &ctx, &Ne, NULL, NULL, NULL, NULL ) == 0 );
        TEST_ASSERT( mbedtls_rsa_export( &ctx, NULL, NULL, NULL, NULL, &Ee ) == 0 );
    }
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &N, &Ne ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &E, &Ee ) == 0 );

    /* If we were providing enough information to setup a complete private context,
     * we expect to be able to export all core parameters. */

    if( is_priv )
    {
        if( !successive )
        {
            TEST_ASSERT( mbedtls_rsa_export( &ctx, NULL, &Pe, &Qe,
                                             &De, NULL ) == 0 );
        }
        else
        {
            TEST_ASSERT( mbedtls_rsa_export( &ctx, NULL, &Pe, NULL,
                                             NULL, NULL ) == 0 );
            TEST_ASSERT( mbedtls_rsa_export( &ctx, NULL, NULL, &Qe,
                                             NULL, NULL ) == 0 );
            TEST_ASSERT( mbedtls_rsa_export( &ctx, NULL, NULL, NULL,
                                             &De, NULL ) == 0 );
        }

        if( have_P )
            TEST_ASSERT( mbedtls_mpi_cmp_mpi( &P, &Pe ) == 0 );

        if( have_Q )
            TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Q, &Qe ) == 0 );

        if( have_D )
            TEST_ASSERT( mbedtls_mpi_cmp_mpi( &D, &De ) == 0 );

        /* While at it, perform a sanity check */
        TEST_ASSERT( mbedtls_rsa_validate_params( &Ne, &Pe, &Qe, &De, &Ee,
                                                       NULL, NULL ) == 0 );
    }

exit:

    mbedtls_rsa_free( &ctx );

    mbedtls_mpi_free( &N );
    mbedtls_mpi_free( &P ); mbedtls_mpi_free( &Q );
    mbedtls_mpi_free( &D ); mbedtls_mpi_free( &E );

    mbedtls_mpi_free( &Ne );
    mbedtls_mpi_free( &Pe ); mbedtls_mpi_free( &Qe );
    mbedtls_mpi_free( &De ); mbedtls_mpi_free( &Ee );
}

void test_mbedtls_rsa_export_wrapper( void ** params )
{

    test_mbedtls_rsa_export( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ), *( (int *) params[11] ) );
}
#if defined(MBEDTLS_ENTROPY_C)
#if defined(ENTROPY_HAVE_STRONG)
#line 1510 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_validate_params( int radix_N, char *input_N,
                                  int radix_P, char *input_P,
                                  int radix_Q, char *input_Q,
                                  int radix_D, char *input_D,
                                  int radix_E, char *input_E,
                                  int prng, int result )
{
    /* Original MPI's with which we set up the RSA context */
    mbedtls_mpi N, P, Q, D, E;

    const int have_N = ( strlen( input_N ) > 0 );
    const int have_P = ( strlen( input_P ) > 0 );
    const int have_Q = ( strlen( input_Q ) > 0 );
    const int have_D = ( strlen( input_D ) > 0 );
    const int have_E = ( strlen( input_E ) > 0 );

    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    const char *pers = "test_suite_rsa";

    mbedtls_mpi_init( &N );
    mbedtls_mpi_init( &P ); mbedtls_mpi_init( &Q );
    mbedtls_mpi_init( &D ); mbedtls_mpi_init( &E );

    mbedtls_ctr_drbg_init( &ctr_drbg );
    mbedtls_entropy_init( &entropy );
    TEST_ASSERT( mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func,
                                        &entropy, (const unsigned char *) pers,
                                        strlen( pers ) ) == 0 );

    if( have_N )
        TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );

    if( have_P )
        TEST_ASSERT( mbedtls_mpi_read_string( &P, radix_P, input_P ) == 0 );

    if( have_Q )
        TEST_ASSERT( mbedtls_mpi_read_string( &Q, radix_Q, input_Q ) == 0 );

    if( have_D )
        TEST_ASSERT( mbedtls_mpi_read_string( &D, radix_D, input_D ) == 0 );

    if( have_E )
        TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );

    TEST_ASSERT( mbedtls_rsa_validate_params( have_N ? &N : NULL,
                                        have_P ? &P : NULL,
                                        have_Q ? &Q : NULL,
                                        have_D ? &D : NULL,
                                        have_E ? &E : NULL,
                                        prng ? mbedtls_ctr_drbg_random : NULL,
                                        prng ? &ctr_drbg : NULL ) == result );
exit:

    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );

    mbedtls_mpi_free( &N );
    mbedtls_mpi_free( &P ); mbedtls_mpi_free( &Q );
    mbedtls_mpi_free( &D ); mbedtls_mpi_free( &E );
}

void test_mbedtls_rsa_validate_params_wrapper( void ** params )
{

    test_mbedtls_rsa_validate_params( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ), *( (int *) params[11] ) );
}
#endif /* ENTROPY_HAVE_STRONG */
#endif /* MBEDTLS_ENTROPY_C */
#if defined(MBEDTLS_CTR_DRBG_C)
#if defined(MBEDTLS_ENTROPY_C)
#line 1574 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_export_raw( data_t *input_N, data_t *input_P,
                             data_t *input_Q, data_t *input_D,
                             data_t *input_E, int is_priv,
                             int successive )
{
    /* Exported buffers */
    unsigned char bufNe[256];
    unsigned char bufPe[128];
    unsigned char bufQe[128];
    unsigned char bufDe[256];
    unsigned char bufEe[1];

    mbedtls_rsa_context ctx;

    mbedtls_rsa_init( &ctx, 0, 0 );

    /* Setup RSA context */
    TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               input_N->len ? input_N->x : NULL, input_N->len,
                               input_P->len ? input_P->x : NULL, input_P->len,
                               input_Q->len ? input_Q->x : NULL, input_Q->len,
                               input_D->len ? input_D->x : NULL, input_D->len,
                               input_E->len ? input_E->x : NULL, input_E->len ) == 0 );

    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == 0 );

    /*
     * Export parameters and compare to original ones.
     */

    /* N and E must always be present. */
    if( !successive )
    {
        TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, bufNe, input_N->len,
                                             NULL, 0, NULL, 0, NULL, 0,
                                             bufEe, input_E->len ) == 0 );
    }
    else
    {
        TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, bufNe, input_N->len,
                                             NULL, 0, NULL, 0, NULL, 0,
                                             NULL, 0 ) == 0 );
        TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, NULL, 0,
                                             NULL, 0, NULL, 0, NULL, 0,
                                             bufEe, input_E->len ) == 0 );
    }
    TEST_ASSERT( memcmp( input_N->x, bufNe, input_N->len ) == 0 );
    TEST_ASSERT( memcmp( input_E->x, bufEe, input_E->len ) == 0 );

    /* If we were providing enough information to setup a complete private context,
     * we expect to be able to export all core parameters. */

    if( is_priv )
    {
        if( !successive )
        {
            TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, NULL, 0,
                                         bufPe, input_P->len ? input_P->len : sizeof( bufPe ),
                                         bufQe, input_Q->len ? input_Q->len : sizeof( bufQe ),
                                         bufDe, input_D->len ? input_D->len : sizeof( bufDe ),
                                         NULL, 0 ) == 0 );
        }
        else
        {
            TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, NULL, 0,
                                         bufPe, input_P->len ? input_P->len : sizeof( bufPe ),
                                         NULL, 0, NULL, 0,
                                         NULL, 0 ) == 0 );

            TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, NULL, 0, NULL, 0,
                                         bufQe, input_Q->len ? input_Q->len : sizeof( bufQe ),
                                         NULL, 0, NULL, 0 ) == 0 );

            TEST_ASSERT( mbedtls_rsa_export_raw( &ctx, NULL, 0, NULL, 0, NULL, 0,
                                         bufDe, input_D->len ? input_D->len : sizeof( bufDe ),
                                         NULL, 0 ) == 0 );
        }

        if( input_P->len )
            TEST_ASSERT( memcmp( input_P->x, bufPe, input_P->len ) == 0 );

        if( input_Q->len )
            TEST_ASSERT( memcmp( input_Q->x, bufQe, input_Q->len ) == 0 );

        if( input_D->len )
            TEST_ASSERT( memcmp( input_D->x, bufDe, input_D->len ) == 0 );

    }

exit:
    mbedtls_rsa_free( &ctx );
}

void test_mbedtls_rsa_export_raw_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_mbedtls_rsa_export_raw( &data0, &data2, &data4, &data6, &data8, *( (int *) params[10] ), *( (int *) params[11] ) );
}
#endif /* MBEDTLS_ENTROPY_C */
#endif /* MBEDTLS_CTR_DRBG_C */
#if defined(MBEDTLS_CTR_DRBG_C)
#if defined(MBEDTLS_ENTROPY_C)
#if defined(ENTROPY_HAVE_STRONG)
#line 1669 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_mbedtls_rsa_import_raw( data_t *input_N,
                             data_t *input_P, data_t *input_Q,
                             data_t *input_D, data_t *input_E,
                             int successive,
                             int is_priv,
                             int res_check,
                             int res_complete )
{
    /* Buffers used for encryption-decryption test */
    unsigned char *buf_orig = NULL;
    unsigned char *buf_enc  = NULL;
    unsigned char *buf_dec  = NULL;

    mbedtls_rsa_context ctx;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;

    const char *pers = "test_suite_rsa";

    mbedtls_ctr_drbg_init( &ctr_drbg );
    mbedtls_entropy_init( &entropy );
    mbedtls_rsa_init( &ctx, 0, 0 );

    TEST_ASSERT( mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func,
                                        &entropy, (const unsigned char *) pers,
                                        strlen( pers ) ) == 0 );

    if( !successive )
    {
        TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               ( input_N->len > 0 ) ? input_N->x : NULL, input_N->len,
                               ( input_P->len > 0 ) ? input_P->x : NULL, input_P->len,
                               ( input_Q->len > 0 ) ? input_Q->x : NULL, input_Q->len,
                               ( input_D->len > 0 ) ? input_D->x : NULL, input_D->len,
                               ( input_E->len > 0 ) ? input_E->x : NULL, input_E->len ) == 0 );
    }
    else
    {
        /* Import N, P, Q, D, E separately.
         * This should make no functional difference. */

        TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               ( input_N->len > 0 ) ? input_N->x : NULL, input_N->len,
                               NULL, 0, NULL, 0, NULL, 0, NULL, 0 ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               NULL, 0,
                               ( input_P->len > 0 ) ? input_P->x : NULL, input_P->len,
                               NULL, 0, NULL, 0, NULL, 0 ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               NULL, 0, NULL, 0,
                               ( input_Q->len > 0 ) ? input_Q->x : NULL, input_Q->len,
                               NULL, 0, NULL, 0 ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               NULL, 0, NULL, 0, NULL, 0,
                               ( input_D->len > 0 ) ? input_D->x : NULL, input_D->len,
                               NULL, 0 ) == 0 );

        TEST_ASSERT( mbedtls_rsa_import_raw( &ctx,
                               NULL, 0, NULL, 0, NULL, 0, NULL, 0,
                               ( input_E->len > 0 ) ? input_E->x : NULL, input_E->len ) == 0 );
    }

    TEST_ASSERT( mbedtls_rsa_complete( &ctx ) == res_complete );

    /* On expected success, perform some public and private
     * key operations to check if the key is working properly. */
    if( res_complete == 0 )
    {
        if( is_priv )
            TEST_ASSERT( mbedtls_rsa_check_privkey( &ctx ) == res_check );
        else
            TEST_ASSERT( mbedtls_rsa_check_pubkey( &ctx ) == res_check );

        if( res_check != 0 )
            goto exit;

        buf_orig = mbedtls_calloc( 1, mbedtls_rsa_get_len( &ctx ) );
        buf_enc  = mbedtls_calloc( 1, mbedtls_rsa_get_len( &ctx ) );
        buf_dec  = mbedtls_calloc( 1, mbedtls_rsa_get_len( &ctx ) );
        if( buf_orig == NULL || buf_enc == NULL || buf_dec == NULL )
            goto exit;

        TEST_ASSERT( mbedtls_ctr_drbg_random( &ctr_drbg,
                              buf_orig, mbedtls_rsa_get_len( &ctx ) ) == 0 );

        /* Make sure the number we're generating is smaller than the modulus */
        buf_orig[0] = 0x00;

        TEST_ASSERT( mbedtls_rsa_public( &ctx, buf_orig, buf_enc ) == 0 );

        if( is_priv )
        {
            TEST_ASSERT( mbedtls_rsa_private( &ctx, mbedtls_ctr_drbg_random,
                                              &ctr_drbg, buf_enc,
                                              buf_dec ) == 0 );

            TEST_ASSERT( memcmp( buf_orig, buf_dec,
                                 mbedtls_rsa_get_len( &ctx ) ) == 0 );
        }
    }

exit:

    mbedtls_free( buf_orig );
    mbedtls_free( buf_enc  );
    mbedtls_free( buf_dec  );

    mbedtls_rsa_free( &ctx );

    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );

}

void test_mbedtls_rsa_import_raw_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_mbedtls_rsa_import_raw( &data0, &data2, &data4, &data6, &data8, *( (int *) params[10] ), *( (int *) params[11] ), *( (int *) params[12] ), *( (int *) params[13] ) );
}
#endif /* ENTROPY_HAVE_STRONG */
#endif /* MBEDTLS_ENTROPY_C */
#endif /* MBEDTLS_CTR_DRBG_C */
#if defined(MBEDTLS_SELF_TEST)
#line 1788 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_rsa.function"
void test_rsa_selftest(  )
{
    TEST_ASSERT( mbedtls_rsa_self_test( 1 ) == 0 );
exit:
    ;
}

void test_rsa_selftest_wrapper( void ** params )
{
    (void)params;

    test_rsa_selftest(  );
}
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_GENPRIME */
#endif /* MBEDTLS_BIGNUM_C */
#endif /* MBEDTLS_RSA_C */


#line 58 "suites/main_test.function"


/*----------------------------------------------------------------------------*/
/* Test dispatch code */


/**
 * \brief       Evaluates an expression/macro into its literal integer value.
 *              For optimizing space for embedded targets each expression/macro
 *              is identified by a unique identifier instead of string literals.
 *              Identifiers and evaluation code is generated by script:
 *              generate_test_code.py
 *
 * \param exp_id    Expression identifier.
 * \param out_value Pointer to int to hold the integer.
 *
 * \return       0 if exp_id is found. 1 otherwise.
 */
int get_expression( int32_t exp_id, int32_t * out_value )
{
    int ret = KEY_VALUE_MAPPING_FOUND;

    (void) exp_id;
    (void) out_value;

    switch( exp_id )
    {

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)

        case 0:
            {
                *out_value = MBEDTLS_RSA_PKCS_V15;
            }
            break;
        case 1:
            {
                *out_value = MBEDTLS_MD_SHA1;
            }
            break;
        case 2:
            {
                *out_value = MBEDTLS_ERR_RSA_VERIFY_FAILED;
            }
            break;
        case 3:
            {
                *out_value = MBEDTLS_MD_SHA224;
            }
            break;
        case 4:
            {
                *out_value = MBEDTLS_MD_SHA256;
            }
            break;
        case 5:
            {
                *out_value = MBEDTLS_MD_SHA384;
            }
            break;
        case 6:
            {
                *out_value = MBEDTLS_MD_SHA512;
            }
            break;
        case 7:
            {
                *out_value = MBEDTLS_MD_MD2;
            }
            break;
        case 8:
            {
                *out_value = MBEDTLS_MD_MD4;
            }
            break;
        case 9:
            {
                *out_value = MBEDTLS_MD_MD5;
            }
            break;
        case 10:
            {
                *out_value = MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
            }
            break;
        case 11:
            {
                *out_value = MBEDTLS_MD_RIPEMD160;
            }
            break;
        case 12:
            {
                *out_value = MBEDTLS_ERR_RSA_PRIVATE_FAILED + MBEDTLS_ERR_MPI_BAD_INPUT_DATA;
            }
            break;
        case 13:
            {
                *out_value = MBEDTLS_ERR_RSA_OUTPUT_TOO_LARGE;
            }
            break;
        case 14:
            {
                *out_value = MBEDTLS_ERR_RSA_KEY_CHECK_FAILED;
            }
            break;
        case 15:
            {
                *out_value = MBEDTLS_ERR_RSA_PUBLIC_FAILED + MBEDTLS_ERR_MPI_BAD_INPUT_DATA;
            }
            break;
        case 16:
            {
                *out_value = MBEDTLS_ERR_MPI_NOT_ACCEPTABLE;
            }
            break;
        case 17:
            {
                *out_value = MBEDTLS_ERR_MPI_BAD_INPUT_DATA;
            }
            break;
        case 18:
            {
                *out_value = MBEDTLS_ERR_RSA_RNG_FAILED;
            }
            break;
#endif

#line 87 "suites/main_test.function"
        default:
           {
                ret = KEY_VALUE_MAPPING_NOT_FOUND;
           }
           break;
    }
    return( ret );
}


/**
 * \brief       Checks if the dependency i.e. the compile flag is set.
 *              For optimizing space for embedded targets each dependency
 *              is identified by a unique identifier instead of string literals.
 *              Identifiers and check code is generated by script:
 *              generate_test_code.py
 *
 * \param exp_id    Dependency identifier.
 *
 * \return       DEPENDENCY_SUPPORTED if set else DEPENDENCY_NOT_SUPPORTED
 */
int dep_check( int dep_id )
{
    int ret = DEPENDENCY_NOT_SUPPORTED;

    (void) dep_id;

    switch( dep_id )
    {

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)

        case 0:
            {
#if defined(MBEDTLS_SHA1_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
            {
#if defined(MBEDTLS_PKCS1_V15)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 2:
            {
#if defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 3:
            {
#if defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 4:
            {
#if !defined(MBEDTLS_SHA512_NO_SHA384)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 5:
            {
#if defined(MBEDTLS_MD2_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 6:
            {
#if defined(MBEDTLS_MD4_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 7:
            {
#if defined(MBEDTLS_MD5_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 8:
            {
#if defined(MBEDTLS_RIPEMD160_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 9:
            {
#if !defined(MBEDTLS_RSA_NO_CRT)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 10:
            {
#if (MBEDTLS_MPI_MAX_SIZE>=1024)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 11:
            {
#if defined(MBEDTLS_SELF_TEST)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
#endif

#line 118 "suites/main_test.function"
        default:
            break;
    }
    return( ret );
}


/**
 * \brief       Function pointer type for test function wrappers.
 *
 *
 * \param void **   Pointer to void pointers. Represents an array of test
 *                  function parameters.
 *
 * \return       void
 */
typedef void (*TestWrapper_t)( void ** );


/**
 * \brief       Table of test function wrappers. Used by dispatch_test().
 *              This table is populated by script:
 *              generate_test_code.py
 *
 */
TestWrapper_t test_funcs[] =
{
/* Function Id: 0 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_CHECK_PARAMS) && !defined(MBEDTLS_PARAM_FAILED_ALT)
    test_rsa_invalid_param_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_pkcs1_sign_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_pkcs1_verify_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_rsa_pkcs1_sign_raw_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_rsa_pkcs1_verify_raw_wrapper,
#else
    NULL,
#endif
/* Function Id: 5 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_pkcs1_encrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 6 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_rsa_pkcs1_encrypt_bad_rng_wrapper,
#else
    NULL,
#endif
/* Function Id: 7 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_pkcs1_decrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 8 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_public_wrapper,
#else
    NULL,
#endif
/* Function Id: 9 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_private_wrapper,
#else
    NULL,
#endif
/* Function Id: 10 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_rsa_check_privkey_null_wrapper,
#else
    NULL,
#endif
/* Function Id: 11 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_check_pubkey_wrapper,
#else
    NULL,
#endif
/* Function Id: 12 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_check_privkey_wrapper,
#else
    NULL,
#endif
/* Function Id: 13 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_rsa_check_pubpriv_wrapper,
#else
    NULL,
#endif
/* Function Id: 14 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_CTR_DRBG_C) && defined(MBEDTLS_ENTROPY_C) && defined(ENTROPY_HAVE_STRONG)
    test_mbedtls_rsa_gen_key_wrapper,
#else
    NULL,
#endif
/* Function Id: 15 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_CTR_DRBG_C) && defined(MBEDTLS_ENTROPY_C)
    test_mbedtls_rsa_deduce_primes_wrapper,
#else
    NULL,
#endif
/* Function Id: 16 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_deduce_private_exponent_wrapper,
#else
    NULL,
#endif
/* Function Id: 17 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_CTR_DRBG_C) && defined(MBEDTLS_ENTROPY_C) && defined(ENTROPY_HAVE_STRONG)
    test_mbedtls_rsa_import_wrapper,
#else
    NULL,
#endif
/* Function Id: 18 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_rsa_export_wrapper,
#else
    NULL,
#endif
/* Function Id: 19 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_ENTROPY_C) && defined(ENTROPY_HAVE_STRONG)
    test_mbedtls_rsa_validate_params_wrapper,
#else
    NULL,
#endif
/* Function Id: 20 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_CTR_DRBG_C) && defined(MBEDTLS_ENTROPY_C)
    test_mbedtls_rsa_export_raw_wrapper,
#else
    NULL,
#endif
/* Function Id: 21 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_CTR_DRBG_C) && defined(MBEDTLS_ENTROPY_C) && defined(ENTROPY_HAVE_STRONG)
    test_mbedtls_rsa_import_raw_wrapper,
#else
    NULL,
#endif
/* Function Id: 22 */

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_SELF_TEST)
    test_rsa_selftest_wrapper,
#else
    NULL,
#endif

#line 147 "suites/main_test.function"
};

/**
 * \brief        Execute the test function.
 *
 *               This is a wrapper function around the test function execution
 *               to allow the setjmp() call used to catch any calls to the
 *               parameter failure callback, to be used. Calls to setjmp()
 *               can invalidate the state of any local auto variables.
 *
 * \param fp     Function pointer to the test function
 * \param params Parameters to pass
 *
 */
void execute_function_ptr(TestWrapper_t fp, void **params)
{
#if defined(MBEDTLS_CHECK_PARAMS)
    if ( setjmp( param_fail_jmp ) == 0 )
    {
        fp( params );
    }
    else
    {
        /* Unexpected parameter validation error */
        test_info.result = TEST_RESULT_FAILED;
    }

    memset( param_fail_jmp, 0, sizeof(jmp_buf) );
#else
    fp( params );
#endif
}

/**
 * \brief        Dispatches test functions based on function index.
 *
 * \param exp_id    Test function index.
 *
 * \return       DISPATCH_TEST_SUCCESS if found
 *               DISPATCH_TEST_FN_NOT_FOUND if not found
 *               DISPATCH_UNSUPPORTED_SUITE if not compile time enabled.
 */
int dispatch_test( int func_idx, void ** params )
{
    int ret = DISPATCH_TEST_SUCCESS;
    TestWrapper_t fp = NULL;

    if ( func_idx < (int)( sizeof( test_funcs ) / sizeof( TestWrapper_t ) ) )
    {
        fp = test_funcs[func_idx];
        if ( fp )
            execute_function_ptr(fp, params);
        else
            ret = DISPATCH_UNSUPPORTED_SUITE;
    }
    else
    {
        ret = DISPATCH_TEST_FN_NOT_FOUND;
    }

    return( ret );
}


/**
 * \brief       Checks if test function is supported
 *
 * \param exp_id    Test function index.
 *
 * \return       DISPATCH_TEST_SUCCESS if found
 *               DISPATCH_TEST_FN_NOT_FOUND if not found
 *               DISPATCH_UNSUPPORTED_SUITE if not compile time enabled.
 */
int check_test( int func_idx )
{
    int ret = DISPATCH_TEST_SUCCESS;
    TestWrapper_t fp = NULL;

    if ( func_idx < (int)( sizeof(test_funcs)/sizeof( TestWrapper_t ) ) )
    {
        fp = test_funcs[func_idx];
        if ( fp == NULL )
            ret = DISPATCH_UNSUPPORTED_SUITE;
    }
    else
    {
        ret = DISPATCH_TEST_FN_NOT_FOUND;
    }

    return( ret );
}


#line 2 "suites/host_test.function"

/**
 * \brief       Verifies that string is in string parameter format i.e. "<str>"
 *              It also strips enclosing '"' from the input string.
 *
 * \param str   String parameter.
 *
 * \return      0 if success else 1
 */
int verify_string( char **str )
{
    if( ( *str )[0] != '"' ||
        ( *str )[strlen( *str ) - 1] != '"' )
    {
        mbedtls_fprintf( stderr,
            "Expected string (with \"\") for parameter and got: %s\n", *str );
        return( -1 );
    }

    ( *str )++;
    ( *str )[strlen( *str ) - 1] = '\0';

    return( 0 );
}

/**
 * \brief       Verifies that string is an integer. Also gives the converted
 *              integer value.
 *
 * \param str   Input string.
 * \param value Pointer to int for output value.
 *
 * \return      0 if success else 1
 */
int verify_int( char *str, int *value )
{
    size_t i;
    int minus = 0;
    int digits = 1;
    int hex = 0;

    for( i = 0; i < strlen( str ); i++ )
    {
        if( i == 0 && str[i] == '-' )
        {
            minus = 1;
            continue;
        }

        if( ( ( minus && i == 2 ) || ( !minus && i == 1 ) ) &&
            str[i - 1] == '0' && ( str[i] == 'x' || str[i] == 'X' ) )
        {
            hex = 1;
            continue;
        }

        if( ! ( ( str[i] >= '0' && str[i] <= '9' ) ||
                ( hex && ( ( str[i] >= 'a' && str[i] <= 'f' ) ||
                           ( str[i] >= 'A' && str[i] <= 'F' ) ) ) ) )
        {
            digits = 0;
            break;
        }
    }

    if( digits )
    {
        if( hex )
            *value = strtol( str, NULL, 16 );
        else
            *value = strtol( str, NULL, 10 );

        return( 0 );
    }

    mbedtls_fprintf( stderr,
                    "Expected integer for parameter and got: %s\n", str );
    return( KEY_VALUE_MAPPING_NOT_FOUND );
}


/**
 * \brief       Usage string.
 *
 */
#define USAGE \
    "Usage: %s [OPTIONS] files...\n\n" \
    "   Command line arguments:\n" \
    "     files...          One or more test data files. If no file is\n" \
    "                       specified the following default test case\n" \
    "                       file is used:\n" \
    "                           %s\n\n" \
    "   Options:\n" \
    "     -v | --verbose    Display full information about each test\n" \
    "     -h | --help       Display this information\n\n", \
    argv[0], \
    "TESTCASE_FILENAME"


/**
 * \brief       Read a line from the passed file pointer.
 *
 * \param f     FILE pointer
 * \param buf   Pointer to memory to hold read line.
 * \param len   Length of the buf.
 *
 * \return      0 if success else -1
 */
int get_line( FILE *f, char *buf, size_t len )
{
    char *ret;
    int i = 0, str_len = 0, has_string = 0;

    /* Read until we get a valid line */
    do
    {
        ret = fgets( buf, len, f );
        if( ret == NULL )
            return( -1 );

        str_len = strlen( buf );

        /* Skip empty line and comment */
        if ( str_len == 0 || buf[0] == '#' )
            continue;
        has_string = 0;
        for ( i = 0; i < str_len; i++ )
        {
            char c = buf[i];
            if ( c != ' ' && c != '\t' && c != '\n' &&
                 c != '\v' && c != '\f' && c != '\r' )
            {
                has_string = 1;
                break;
            }
        }
    } while( !has_string );

    /* Strip new line and carriage return */
    ret = buf + strlen( buf );
    if( ret-- > buf && *ret == '\n' )
        *ret = '\0';
    if( ret-- > buf && *ret == '\r' )
        *ret = '\0';

    return( 0 );
}

/**
 * \brief       Splits string delimited by ':'. Ignores '\:'.
 *
 * \param buf           Input string
 * \param len           Input string length
 * \param params        Out params found
 * \param params_len    Out params array len
 *
 * \return      Count of strings found.
 */
static int parse_arguments( char *buf, size_t len, char **params,
                            size_t params_len )
{
    size_t cnt = 0, i;
    char *cur = buf;
    char *p = buf, *q;

    params[cnt++] = cur;

    while( *p != '\0' && p < ( buf + len ) )
    {
        if( *p == '\\' )
        {
            p++;
            p++;
            continue;
        }
        if( *p == ':' )
        {
            if( p + 1 < buf + len )
            {
                cur = p + 1;
                TEST_HELPER_ASSERT( cnt < params_len );
                params[cnt++] = cur;
            }
            *p = '\0';
        }

        p++;
    }

    /* Replace newlines, question marks and colons in strings */
    for( i = 0; i < cnt; i++ )
    {
        p = params[i];
        q = params[i];

        while( *p != '\0' )
        {
            if( *p == '\\' && *( p + 1 ) == 'n' )
            {
                p += 2;
                *( q++ ) = '\n';
            }
            else if( *p == '\\' && *( p + 1 ) == ':' )
            {
                p += 2;
                *( q++ ) = ':';
            }
            else if( *p == '\\' && *( p + 1 ) == '?' )
            {
                p += 2;
                *( q++ ) = '?';
            }
            else
                *( q++ ) = *( p++ );
        }
        *q = '\0';
    }

    return( cnt );
}

/**
 * \brief       Converts parameters into test function consumable parameters.
 *              Example: Input:  {"int", "0", "char*", "Hello",
 *                                "hex", "abef", "exp", "1"}
 *                      Output:  {
 *                                0,                // Verified int
 *                                "Hello",          // Verified string
 *                                2, { 0xab, 0xef },// Converted len,hex pair
 *                                9600              // Evaluated expression
 *                               }
 *
 *
 * \param cnt               Parameter array count.
 * \param params            Out array of found parameters.
 * \param int_params_store  Memory for storing processed integer parameters.
 *
 * \return      0 for success else 1
 */
static int convert_params( size_t cnt , char ** params , int * int_params_store )
{
    char ** cur = params;
    char ** out = params;
    int ret = DISPATCH_TEST_SUCCESS;

    while ( cur < params + cnt )
    {
        char * type = *cur++;
        char * val = *cur++;

        if ( strcmp( type, "char*" ) == 0 )
        {
            if ( verify_string( &val ) == 0 )
            {
              *out++ = val;
            }
            else
            {
                ret = ( DISPATCH_INVALID_TEST_DATA );
                break;
            }
        }
        else if ( strcmp( type, "int" ) == 0 )
        {
            if ( verify_int( val, int_params_store ) == 0 )
            {
              *out++ = (char *) int_params_store++;
            }
            else
            {
                ret = ( DISPATCH_INVALID_TEST_DATA );
                break;
            }
        }
        else if ( strcmp( type, "hex" ) == 0 )
        {
            if ( verify_string( &val ) == 0 )
            {
                *int_params_store = unhexify( (unsigned char *) val, val );
                *out++ = val;
                *out++ = (char *)(int_params_store++);
            }
            else
            {
                ret = ( DISPATCH_INVALID_TEST_DATA );
                break;
            }
        }
        else if ( strcmp( type, "exp" ) == 0 )
        {
            int exp_id = strtol( val, NULL, 10 );
            if ( get_expression ( exp_id, int_params_store ) == 0 )
            {
              *out++ = (char *)int_params_store++;
            }
            else
            {
              ret = ( DISPATCH_INVALID_TEST_DATA );
              break;
            }
        }
        else
        {
          ret = ( DISPATCH_INVALID_TEST_DATA );
          break;
        }
    }
    return( ret );
}

/**
 * \brief       Tests snprintf implementation with test input.
 *
 * \note
 * At high optimization levels (e.g. gcc -O3), this function may be
 * inlined in run_test_snprintf. This can trigger a spurious warning about
 * potential misuse of snprintf from gcc -Wformat-truncation (observed with
 * gcc 7.2). This warning makes tests in run_test_snprintf redundant on gcc
 * only. They are still valid for other compilers. Avoid this warning by
 * forbidding inlining of this function by gcc.
 *
 * \param n         Buffer test length.
 * \param ref_buf   Expected buffer.
 * \param ref_ret   Expected snprintf return value.
 *
 * \return      0 for success else 1
 */
#if defined(__GNUC__)
__attribute__((__noinline__))
#endif
static int test_snprintf( size_t n, const char ref_buf[10], int ref_ret )
{
    int ret;
    char buf[10] = "xxxxxxxxx";
    const char ref[10] = "xxxxxxxxx";

    if( n >= sizeof( buf ) )
        return( -1 );
    ret = mbedtls_snprintf( buf, n, "%s", "123" );
    if( ret < 0 || (size_t) ret >= n )
        ret = -1;

    if( strncmp( ref_buf, buf, sizeof( buf ) ) != 0 ||
        ref_ret != ret ||
        memcmp( buf + n, ref + n, sizeof( buf ) - n ) != 0 )
    {
        return( 1 );
    }

    return( 0 );
}

/**
 * \brief       Tests snprintf implementation.
 *
 * \param none
 *
 * \return      0 for success else 1
 */
static int run_test_snprintf( void )
{
    return( test_snprintf( 0, "xxxxxxxxx",  -1 ) != 0 ||
            test_snprintf( 1, "",           -1 ) != 0 ||
            test_snprintf( 2, "1",          -1 ) != 0 ||
            test_snprintf( 3, "12",         -1 ) != 0 ||
            test_snprintf( 4, "123",         3 ) != 0 ||
            test_snprintf( 5, "123",         3 ) != 0 );
}

/** \brief Write the description of the test case to the outcome CSV file.
 *
 * \param outcome_file  The file to write to.
 *                      If this is \c NULL, this function does nothing.
 * \param argv0         The test suite name.
 * \param test_case     The test case description.
 */
static void write_outcome_entry( FILE *outcome_file,
                                 const char *argv0,
                                 const char *test_case )
{
    /* The non-varying fields are initialized on first use. */
    static const char *platform = NULL;
    static const char *configuration = NULL;
    static const char *test_suite = NULL;

    if( outcome_file == NULL )
        return;

    if( platform == NULL )
    {
        platform = getenv( "MBEDTLS_TEST_PLATFORM" );
        if( platform == NULL )
            platform = "unknown";
    }
    if( configuration == NULL )
    {
        configuration = getenv( "MBEDTLS_TEST_CONFIGURATION" );
        if( configuration == NULL )
            configuration = "unknown";
    }
    if( test_suite == NULL )
    {
        test_suite = strrchr( argv0, '/' );
        if( test_suite != NULL )
            test_suite += 1; // skip the '/'
        else
            test_suite = argv0;
    }

    /* Write the beginning of the outcome line.
     * Ignore errors: writing the outcome file is on a best-effort basis. */
    mbedtls_fprintf( outcome_file, "%s;%s;%s;%s;",
                     platform, configuration, test_suite, test_case );
}

/** \brief Write the result of the test case to the outcome CSV file.
 *
 * \param outcome_file  The file to write to.
 *                      If this is \c NULL, this function does nothing.
 * \param unmet_dep_count       The number of unmet dependencies.
 * \param unmet_dependencies    The array of unmet dependencies.
 * \param ret           The test dispatch status (DISPATCH_xxx).
 * \param test_info     A pointer to the test info structure.
 */
static void write_outcome_result( FILE *outcome_file,
                                  size_t unmet_dep_count,
                                  char *unmet_dependencies[],
                                  int ret,
                                  const test_info_t *info )
{
    if( outcome_file == NULL )
        return;

    /* Write the end of the outcome line.
     * Ignore errors: writing the outcome file is on a best-effort basis. */
    switch( ret )
    {
        case DISPATCH_TEST_SUCCESS:
            if( unmet_dep_count > 0 )
            {
                size_t i;
                mbedtls_fprintf( outcome_file, "SKIP" );
                for( i = 0; i < unmet_dep_count; i++ )
                {
                    mbedtls_fprintf( outcome_file, "%c%s",
                                     i == 0 ? ';' : ':',
                                     unmet_dependencies[i] );
                }
                break;
            }
            switch( info->result )
            {
                case TEST_RESULT_SUCCESS:
                    mbedtls_fprintf( outcome_file, "PASS;" );
                    break;
                case TEST_RESULT_SKIPPED:
                    mbedtls_fprintf( outcome_file, "SKIP;Runtime skip" );
                    break;
                default:
                    mbedtls_fprintf( outcome_file, "FAIL;%s:%d:%s",
                                     info->filename, info->line_no,
                                     info->test );
                    break;
            }
            break;
        case DISPATCH_TEST_FN_NOT_FOUND:
            mbedtls_fprintf( outcome_file, "FAIL;Test function not found" );
            break;
        case DISPATCH_INVALID_TEST_DATA:
            mbedtls_fprintf( outcome_file, "FAIL;Invalid test data" );
            break;
        case DISPATCH_UNSUPPORTED_SUITE:
            mbedtls_fprintf( outcome_file, "SKIP;Unsupported suite" );
            break;
        default:
            mbedtls_fprintf( outcome_file, "FAIL;Unknown cause" );
            break;
    }
    mbedtls_fprintf( outcome_file, "\n" );
    fflush( outcome_file );
}

/**
 * \brief       Desktop implementation of execute_tests().
 *              Parses command line and executes tests from
 *              supplied or default data file.
 *
 * \param argc  Command line argument count.
 * \param argv  Argument array.
 *
 * \return      Program exit status.
 */
int execute_tests( int argc , const char ** argv )
{
    /* Local Configurations and options */
    const char *default_filename = "./test_suite_rsa.datax";
    const char *test_filename = NULL;
    const char **test_files = NULL;
    size_t testfile_count = 0;
    int option_verbose = 0;
    int function_id = 0;

    /* Other Local variables */
    int arg_index = 1;
    const char *next_arg;
    size_t testfile_index, i, cnt;
    int ret;
    unsigned total_errors = 0, total_tests = 0, total_skipped = 0;
    FILE *file;
    char buf[5000];
    char *params[50];
    /* Store for proccessed integer params. */
    int int_params[50];
    void *pointer;
#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
    int stdout_fd = -1;
#endif /* __unix__ || __APPLE__ __MACH__ */
    const char *outcome_file_name = getenv( "MBEDTLS_TEST_OUTCOME_FILE" );
    FILE *outcome_file = NULL;

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && \
    !defined(TEST_SUITE_MEMORY_BUFFER_ALLOC)
    unsigned char alloc_buf[1000000];
    mbedtls_memory_buffer_alloc_init( alloc_buf, sizeof( alloc_buf ) );
#endif

    /*
     * The C standard doesn't guarantee that all-bits-0 is the representation
     * of a NULL pointer. We do however use that in our code for initializing
     * structures, which should work on every modern platform. Let's be sure.
     */
    memset( &pointer, 0, sizeof( void * ) );
    if( pointer != NULL )
    {
        mbedtls_fprintf( stderr, "all-bits-zero is not a NULL pointer\n" );
        return( 1 );
    }

    /*
     * Make sure we have a snprintf that correctly zero-terminates
     */
    if( run_test_snprintf() != 0 )
    {
        mbedtls_fprintf( stderr, "the snprintf implementation is broken\n" );
        return( 1 );
    }

    if( outcome_file_name != NULL )
    {
        outcome_file = fopen( outcome_file_name, "a" );
        if( outcome_file == NULL )
        {
            mbedtls_fprintf( stderr, "Unable to open outcome file. Continuing anyway.\n" );
        }
    }

    while( arg_index < argc )
    {
        next_arg = argv[arg_index];

        if( strcmp( next_arg, "--verbose" ) == 0 ||
                 strcmp( next_arg, "-v" ) == 0 )
        {
            option_verbose = 1;
        }
        else if( strcmp(next_arg, "--help" ) == 0 ||
                 strcmp(next_arg, "-h" ) == 0 )
        {
            mbedtls_fprintf( stdout, USAGE );
            mbedtls_exit( EXIT_SUCCESS );
        }
        else
        {
            /* Not an option, therefore treat all further arguments as the file
             * list.
             */
            test_files = &argv[ arg_index ];
            testfile_count = argc - arg_index;
        }

        arg_index++;
    }

    /* If no files were specified, assume a default */
    if ( test_files == NULL || testfile_count == 0 )
    {
        test_files = &default_filename;
        testfile_count = 1;
    }

    /* Initialize the struct that holds information about the last test */
    memset( &test_info, 0, sizeof( test_info ) );

    /* Now begin to execute the tests in the testfiles */
    for ( testfile_index = 0;
          testfile_index < testfile_count;
          testfile_index++ )
    {
        size_t unmet_dep_count = 0;
        char *unmet_dependencies[20];

        test_filename = test_files[ testfile_index ];

        file = fopen( test_filename, "r" );
        if( file == NULL )
        {
            mbedtls_fprintf( stderr, "Failed to open test file: %s\n",
                             test_filename );
            if( outcome_file != NULL )
                fclose( outcome_file );
            return( 1 );
        }

        while( !feof( file ) )
        {
            if( unmet_dep_count > 0 )
            {
                mbedtls_fprintf( stderr,
                    "FATAL: Dep count larger than zero at start of loop\n" );
                mbedtls_exit( MBEDTLS_EXIT_FAILURE );
            }
            unmet_dep_count = 0;

            if( ( ret = get_line( file, buf, sizeof(buf) ) ) != 0 )
                break;
            mbedtls_fprintf( stdout, "%s%.66s",
                    test_info.result == TEST_RESULT_FAILED ? "\n" : "", buf );
            mbedtls_fprintf( stdout, " " );
            for( i = strlen( buf ) + 1; i < 67; i++ )
                mbedtls_fprintf( stdout, "." );
            mbedtls_fprintf( stdout, " " );
            fflush( stdout );
            write_outcome_entry( outcome_file, argv[0], buf );

            total_tests++;

            if( ( ret = get_line( file, buf, sizeof( buf ) ) ) != 0 )
                break;
            cnt = parse_arguments( buf, strlen( buf ), params,
                                   sizeof( params ) / sizeof( params[0] ) );

            if( strcmp( params[0], "depends_on" ) == 0 )
            {
                for( i = 1; i < cnt; i++ )
                {
                    int dep_id = strtol( params[i], NULL, 10 );
                    if( dep_check( dep_id ) != DEPENDENCY_SUPPORTED )
                    {
                        if( 0 == option_verbose )
                        {
                            /* Only one count is needed if not verbose */
                            unmet_dep_count++;
                            break;
                        }

                        unmet_dependencies[ unmet_dep_count ] = strdup( params[i] );
                        if(  unmet_dependencies[ unmet_dep_count ] == NULL )
                        {
                            mbedtls_fprintf( stderr, "FATAL: Out of memory\n" );
                            mbedtls_exit( MBEDTLS_EXIT_FAILURE );
                        }
                        unmet_dep_count++;
                    }
                }

                if( ( ret = get_line( file, buf, sizeof( buf ) ) ) != 0 )
                    break;
                cnt = parse_arguments( buf, strlen( buf ), params,
                                       sizeof( params ) / sizeof( params[0] ) );
            }

            // If there are no unmet dependencies execute the test
            if( unmet_dep_count == 0 )
            {
                test_info.result = TEST_RESULT_SUCCESS;
                test_info.paramfail_test_state = PARAMFAIL_TESTSTATE_IDLE;
                test_info.step = (unsigned long)( -1 );

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
                /* Suppress all output from the library unless we're verbose
                 * mode
                 */
                if( !option_verbose )
                {
                    stdout_fd = redirect_output( &stdout, "/dev/null" );
                    if( stdout_fd == -1 )
                    {
                        /* Redirection has failed with no stdout so exit */
                        exit( 1 );
                    }
                }
#endif /* __unix__ || __APPLE__ __MACH__ */

                function_id = strtol( params[0], NULL, 10 );
                if ( (ret = check_test( function_id )) == DISPATCH_TEST_SUCCESS )
                {
                    ret = convert_params( cnt - 1, params + 1, int_params );
                    if ( DISPATCH_TEST_SUCCESS == ret )
                    {
                        ret = dispatch_test( function_id, (void **)( params + 1 ) );
                    }
                }

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
                if( !option_verbose && restore_output( &stdout, stdout_fd ) )
                {
                        /* Redirection has failed with no stdout so exit */
                        exit( 1 );
                }
#endif /* __unix__ || __APPLE__ __MACH__ */

            }

            write_outcome_result( outcome_file,
                                  unmet_dep_count, unmet_dependencies,
                                  ret, &test_info );
            if( unmet_dep_count > 0 || ret == DISPATCH_UNSUPPORTED_SUITE )
            {
                total_skipped++;
                mbedtls_fprintf( stdout, "----" );

                if( 1 == option_verbose && ret == DISPATCH_UNSUPPORTED_SUITE )
                {
                    mbedtls_fprintf( stdout, "\n   Test Suite not enabled" );
                }

                if( 1 == option_verbose && unmet_dep_count > 0 )
                {
                    mbedtls_fprintf( stdout, "\n   Unmet dependencies: " );
                    for( i = 0; i < unmet_dep_count; i++ )
                    {
                        mbedtls_fprintf( stdout, "%s  ",
                                        unmet_dependencies[i] );
                        free( unmet_dependencies[i] );
                    }
                }
                mbedtls_fprintf( stdout, "\n" );
                fflush( stdout );

                unmet_dep_count = 0;
            }
            else if( ret == DISPATCH_TEST_SUCCESS )
            {
                if( test_info.result == TEST_RESULT_SUCCESS )
                {
                    mbedtls_fprintf( stdout, "PASS\n" );
                }
                else if( test_info.result == TEST_RESULT_SKIPPED )
                {
                    mbedtls_fprintf( stdout, "----\n" );
                    total_skipped++;
                }
                else
                {
                    total_errors++;
                    mbedtls_fprintf( stdout, "FAILED\n" );
                    mbedtls_fprintf( stdout, "  %s\n  at ",
                                     test_info.test );
                    if( test_info.step != (unsigned long)( -1 ) )
                    {
                        mbedtls_fprintf( stdout, "step %lu, ",
                                         test_info.step );
                    }
                    mbedtls_fprintf( stdout, "line %d, %s",
                                     test_info.line_no, test_info.filename );
                }
                fflush( stdout );
            }
            else if( ret == DISPATCH_INVALID_TEST_DATA )
            {
                mbedtls_fprintf( stderr, "FAILED: FATAL PARSE ERROR\n" );
                fclose( file );
                mbedtls_exit( 2 );
            }
            else if( ret == DISPATCH_TEST_FN_NOT_FOUND )
            {
                mbedtls_fprintf( stderr, "FAILED: FATAL TEST FUNCTION NOT FOUND\n" );
                fclose( file );
                mbedtls_exit( 2 );
            }
            else
                total_errors++;
        }
        fclose( file );

        /* In case we encounter early end of file */
        for( i = 0; i < unmet_dep_count; i++ )
            free( unmet_dependencies[i] );
    }

    if( outcome_file != NULL )
        fclose( outcome_file );

    mbedtls_fprintf( stdout, "\n----------------------------------------------------------------------------\n\n");
    if( total_errors == 0 )
        mbedtls_fprintf( stdout, "PASSED" );
    else
        mbedtls_fprintf( stdout, "FAILED" );

    mbedtls_fprintf( stdout, " (%u / %u tests (%u skipped))\n",
                     total_tests - total_errors, total_tests, total_skipped );

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && \
    !defined(TEST_SUITE_MEMORY_BUFFER_ALLOC)
#if defined(MBEDTLS_MEMORY_DEBUG)
    mbedtls_memory_buffer_alloc_status();
#endif
    mbedtls_memory_buffer_alloc_free();
#endif

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
    if( stdout_fd != -1 )
        close_output( stdout );
#endif /* __unix__ || __APPLE__ __MACH__ */

    return( total_errors != 0 );
}


#line 243 "suites/main_test.function"

/*----------------------------------------------------------------------------*/
/* Main Test code */


/**
 * \brief       Program main. Invokes platform specific execute_tests().
 *
 * \param argc      Command line arguments count.
 * \param argv      Array of command line arguments.
 *
 * \return       Exit code.
 */
int main( int argc, const char *argv[] )
{
    int ret = platform_setup();
    if( ret != 0 )
    {
        mbedtls_fprintf( stderr,
                         "FATAL: Failed to initialize platform - error %d\n",
                         ret );
        return( -1 );
    }

    ret = execute_tests( argc, argv );
    platform_teardown();
    return( ret );
}
