#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_psa_crypto.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/main_test.function
 *      Platform code file  : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/host_test.function
 *      Helper file         : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/helpers.function
 *      Test suite file     : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function
 *      Test suite data     : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.data
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

#if defined(MBEDTLS_PSA_CRYPTO_C)
#line 2 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
#include <stdint.h>

#include "mbedtls/asn1.h"
#include "mbedtls/asn1write.h"
#include "mbedtls/oid.h"

/* For MBEDTLS_CTR_DRBG_MAX_REQUEST, knowing that psa_generate_random()
 * uses mbedtls_ctr_drbg internally. */
#include "mbedtls/ctr_drbg.h"

#include "psa_crypto_helpers.h"

/* Tests that require more than 128kB of RAM plus change have this symbol
 * as a dependency. Currently we always define this symbol, so the tests
 * are always executed. In the future we should make this conditional
 * so that tests that require a lot of memory are skipped on constrained
 * platforms. */
#define HAVE_RAM_AVAILABLE_128K

#include "psa/crypto.h"

/** An invalid export length that will never be set by psa_export_key(). */
static const size_t INVALID_EXPORT_LENGTH = ~0U;

/* A hash algorithm that is known to be supported.
 *
 * This is used in some smoke tests.
 */
#if defined(MBEDTLS_MD2_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_MD2
#elif defined(MBEDTLS_MD4_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_MD4
#elif defined(MBEDTLS_MD5_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_MD5
/* MBEDTLS_RIPEMD160_C omitted. This is necessary for the sake of
 * exercise_signature_key() because Mbed TLS doesn't support RIPEMD160
 * in RSA PKCS#1v1.5 signatures. A RIPEMD160-only configuration would be
 * implausible anyway. */
#elif defined(MBEDTLS_SHA1_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_SHA_1
#elif defined(MBEDTLS_SHA256_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_SHA_256
#elif defined(MBEDTLS_SHA512_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_SHA_384
#elif defined(MBEDTLS_SHA3_C)
#define KNOWN_SUPPORTED_HASH_ALG PSA_ALG_SHA3_256
#else
#undef KNOWN_SUPPORTED_HASH_ALG
#endif

/* A block cipher that is known to be supported.
 *
 * For simplicity's sake, stick to block ciphers with 16-byte blocks.
 */
#if defined(MBEDTLS_AES_C)
#define KNOWN_SUPPORTED_BLOCK_CIPHER PSA_KEY_TYPE_AES
#elif defined(MBEDTLS_ARIA_C)
#define KNOWN_SUPPORTED_BLOCK_CIPHER PSA_KEY_TYPE_ARIA
#elif defined(MBEDTLS_CAMELLIA_C)
#define KNOWN_SUPPORTED_BLOCK_CIPHER PSA_KEY_TYPE_CAMELLIA
#undef KNOWN_SUPPORTED_BLOCK_CIPHER
#endif

/* A MAC mode that is known to be supported.
 *
 * It must either be HMAC with #KNOWN_SUPPORTED_HASH_ALG or
 * a block cipher-based MAC with #KNOWN_SUPPORTED_BLOCK_CIPHER.
 *
 * This is used in some smoke tests.
 */
#if defined(KNOWN_SUPPORTED_HASH_ALG)
#define KNOWN_SUPPORTED_MAC_ALG ( PSA_ALG_HMAC( KNOWN_SUPPORTED_HASH_ALG ) )
#define KNOWN_SUPPORTED_MAC_KEY_TYPE PSA_KEY_TYPE_HMAC
#elif defined(KNOWN_SUPPORTED_BLOCK_CIPHER) && defined(MBEDTLS_CMAC_C)
#define KNOWN_SUPPORTED_MAC_ALG PSA_ALG_CMAC
#define KNOWN_SUPPORTED_MAC_KEY_TYPE KNOWN_SUPPORTED_BLOCK_CIPHER
#else
#undef KNOWN_SUPPORTED_MAC_ALG
#undef KNOWN_SUPPORTED_MAC_KEY_TYPE
#endif

/* A cipher algorithm and key type that are known to be supported.
 *
 * This is used in some smoke tests.
 */
#if defined(KNOWN_SUPPORTED_BLOCK_CIPHER) && defined(MBEDTLS_CIPHER_MODE_CTR)
#define KNOWN_SUPPORTED_BLOCK_CIPHER_ALG PSA_ALG_CTR
#elif defined(KNOWN_SUPPORTED_BLOCK_CIPHER) && defined(MBEDTLS_CIPHER_MODE_CBC)
#define KNOWN_SUPPORTED_BLOCK_CIPHER_ALG PSA_ALG_CBC_NO_PADDING
#elif defined(KNOWN_SUPPORTED_BLOCK_CIPHER) && defined(MBEDTLS_CIPHER_MODE_CFB)
#define KNOWN_SUPPORTED_BLOCK_CIPHER_ALG PSA_ALG_CFB
#elif defined(KNOWN_SUPPORTED_BLOCK_CIPHER) && defined(MBEDTLS_CIPHER_MODE_OFB)
#define KNOWN_SUPPORTED_BLOCK_CIPHER_ALG PSA_ALG_OFB
#else
#undef KNOWN_SUPPORTED_BLOCK_CIPHER_ALG
#endif
#if defined(KNOWN_SUPPORTED_BLOCK_CIPHER_ALG)
#define KNOWN_SUPPORTED_CIPHER_ALG KNOWN_SUPPORTED_BLOCK_CIPHER_ALG
#define KNOWN_SUPPORTED_CIPHER_KEY_TYPE KNOWN_SUPPORTED_BLOCK_CIPHER
#elif defined(MBEDTLS_RC4_C)
#define KNOWN_SUPPORTED_CIPHER_ALG PSA_ALG_RC4
#define KNOWN_SUPPORTED_CIPHER_KEY_TYPE PSA_KEY_TYPE_RC4
#else
#undef KNOWN_SUPPORTED_CIPHER_ALG
#undef KNOWN_SUPPORTED_CIPHER_KEY_TYPE
#endif

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
int lifetime_is_secure_element( psa_key_lifetime_t lifetime )
{
    /* At the moment, anything that isn't a built-in lifetime is either
     * a secure element or unassigned. */
    return( lifetime != PSA_KEY_LIFETIME_VOLATILE &&
            lifetime != PSA_KEY_LIFETIME_PERSISTENT );
}
#else
int lifetime_is_secure_element( psa_key_lifetime_t lifetime )
{
    (void) lifetime;
    return( 0 );
}
#endif

/** Test if a buffer contains a constant byte value.
 *
 * `mem_is_char(buffer, c, size)` is true after `memset(buffer, c, size)`.
 *
 * \param buffer    Pointer to the beginning of the buffer.
 * \param c         Expected value of every byte.
 * \param size      Size of the buffer in bytes.
 *
 * \return          1 if the buffer is all-bits-zero.
 * \return          0 if there is at least one nonzero byte.
 */
static int mem_is_char( void *buffer, unsigned char c, size_t size )
{
    size_t i;
    for( i = 0; i < size; i++ )
    {
        if( ( (unsigned char *) buffer )[i] != c )
            return( 0 );
    }
    return( 1 );
}

/* Write the ASN.1 INTEGER with the value 2^(bits-1)+x backwards from *p. */
static int asn1_write_10x( unsigned char **p,
                           unsigned char *start,
                           size_t bits,
                           unsigned char x )
{
    int ret;
    int len = bits / 8 + 1;
    if( bits == 0 )
        return( MBEDTLS_ERR_ASN1_INVALID_DATA );
    if( bits <= 8 && x >= 1 << ( bits - 1 ) )
        return( MBEDTLS_ERR_ASN1_INVALID_DATA );
    if( *p < start || *p - start < (ptrdiff_t) len )
        return( MBEDTLS_ERR_ASN1_BUF_TOO_SMALL );
    *p -= len;
    ( *p )[len-1] = x;
    if( bits % 8 == 0 )
        ( *p )[1] |= 1;
    else
        ( *p )[0] |= 1 << ( bits % 8 );
    MBEDTLS_ASN1_CHK_ADD( len, mbedtls_asn1_write_len( p, start, len ) );
    MBEDTLS_ASN1_CHK_ADD( len, mbedtls_asn1_write_tag( p, start,
                                                       MBEDTLS_ASN1_INTEGER ) );
    return( len );
}

static int construct_fake_rsa_key( unsigned char *buffer,
                                   size_t buffer_size,
                                   unsigned char **p,
                                   size_t bits,
                                   int keypair )
{
    size_t half_bits = ( bits + 1 ) / 2;
    int ret;
    int len = 0;
    /* Construct something that looks like a DER encoding of
     * as defined by PKCS#1 v2.2 (RFC 8017) section A.1.2:
     *   RSAPrivateKey ::= SEQUENCE {
     *       version           Version,
     *       modulus           INTEGER,  -- n
     *       publicExponent    INTEGER,  -- e
     *       privateExponent   INTEGER,  -- d
     *       prime1            INTEGER,  -- p
     *       prime2            INTEGER,  -- q
     *       exponent1         INTEGER,  -- d mod (p-1)
     *       exponent2         INTEGER,  -- d mod (q-1)
     *       coefficient       INTEGER,  -- (inverse of q) mod p
     *       otherPrimeInfos   OtherPrimeInfos OPTIONAL
     *   }
     * Or, for a public key, the same structure with only
     * version, modulus and publicExponent.
     */
    *p = buffer + buffer_size;
    if( keypair )
    {
        MBEDTLS_ASN1_CHK_ADD( len, /* pq */
                              asn1_write_10x( p, buffer, half_bits, 1 ) );
        MBEDTLS_ASN1_CHK_ADD( len, /* dq */
                              asn1_write_10x( p, buffer, half_bits, 1 ) );
        MBEDTLS_ASN1_CHK_ADD( len, /* dp */
                              asn1_write_10x( p, buffer, half_bits, 1 ) );
        MBEDTLS_ASN1_CHK_ADD( len, /* q */
                              asn1_write_10x( p, buffer, half_bits, 1 ) );
        MBEDTLS_ASN1_CHK_ADD( len, /* p != q to pass mbedtls sanity checks */
                              asn1_write_10x( p, buffer, half_bits, 3 ) );
        MBEDTLS_ASN1_CHK_ADD( len, /* d */
                              asn1_write_10x( p, buffer, bits, 1 ) );
    }
    MBEDTLS_ASN1_CHK_ADD( len, /* e = 65537 */
                          asn1_write_10x( p, buffer, 17, 1 ) );
    MBEDTLS_ASN1_CHK_ADD( len, /* n */
                          asn1_write_10x( p, buffer, bits, 1 ) );
    if( keypair )
        MBEDTLS_ASN1_CHK_ADD( len, /* version = 0 */
                              mbedtls_asn1_write_int( p, buffer, 0 ) );
    MBEDTLS_ASN1_CHK_ADD( len, mbedtls_asn1_write_len( p, buffer, len ) );
    {
        const unsigned char tag =
            MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE;
        MBEDTLS_ASN1_CHK_ADD( len, mbedtls_asn1_write_tag( p, buffer, tag ) );
    }
    return( len );
}

int check_key_attributes_sanity( psa_key_handle_t key )
{
    int ok = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_lifetime_t lifetime;
    psa_key_id_t id;
    psa_key_type_t type;
    psa_key_type_t bits;

    PSA_ASSERT( psa_get_key_attributes( key, &attributes ) );
    lifetime = psa_get_key_lifetime( &attributes );
    id = psa_get_key_id( &attributes );
    type = psa_get_key_type( &attributes );
    bits = psa_get_key_bits( &attributes );

    /* Persistence */
    if( lifetime == PSA_KEY_LIFETIME_VOLATILE )
        TEST_ASSERT( id == 0 );
    else
    {
        TEST_ASSERT(
            ( PSA_KEY_ID_USER_MIN <= id && id <= PSA_KEY_ID_USER_MAX ) ||
            ( PSA_KEY_ID_USER_MIN <= id && id <= PSA_KEY_ID_USER_MAX ) );
    }
#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    /* randomly-generated 64-bit constant, should never appear in test data */
    psa_key_slot_number_t slot_number = 0xec94d4a5058a1a21;
    psa_status_t status = psa_get_key_slot_number( &attributes, &slot_number );
    if( lifetime_is_secure_element( lifetime ) )
    {
        /* Mbed Crypto currently always exposes the slot number to
         * applications. This is not mandated by the PSA specification
         * and may change in future versions. */
        TEST_EQUAL( status, 0 );
        TEST_ASSERT( slot_number != 0xec94d4a5058a1a21 );
    }
    else
    {
        TEST_EQUAL( status, PSA_ERROR_INVALID_ARGUMENT );
    }
#endif

    /* Type and size */
    TEST_ASSERT( type != 0 );
    TEST_ASSERT( bits != 0 );
    TEST_ASSERT( bits <= PSA_MAX_KEY_BITS );
    if( PSA_KEY_TYPE_IS_UNSTRUCTURED( type ) )
        TEST_ASSERT( bits % 8 == 0 );

    /* MAX macros concerning specific key types */
    if( PSA_KEY_TYPE_IS_ECC( type ) )
        TEST_ASSERT( bits <= PSA_VENDOR_ECC_MAX_CURVE_BITS );
    else if( PSA_KEY_TYPE_IS_RSA( type ) )
        TEST_ASSERT( bits <= PSA_VENDOR_RSA_MAX_KEY_BITS );
    TEST_ASSERT( PSA_BLOCK_CIPHER_BLOCK_SIZE( type ) <= PSA_MAX_BLOCK_CIPHER_BLOCK_SIZE );

    ok = 1;

exit:
    psa_reset_key_attributes( &attributes );
    return( ok );
}

int exercise_mac_setup( psa_key_type_t key_type,
                        const unsigned char *key_bytes,
                        size_t key_length,
                        psa_algorithm_t alg,
                        psa_mac_operation_t *operation,
                        psa_status_t *status )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );
    PSA_ASSERT( psa_import_key( &attributes, key_bytes, key_length,
                                &handle ) );

    *status = psa_mac_sign_setup( operation, handle, alg );
    /* Whether setup succeeded or failed, abort must succeed. */
    PSA_ASSERT( psa_mac_abort( operation ) );
    /* If setup failed, reproduce the failure, so that the caller can
     * test the resulting state of the operation object. */
    if( *status != PSA_SUCCESS )
    {
        TEST_EQUAL( psa_mac_sign_setup( operation, handle, alg ),
                    *status );
    }

    psa_destroy_key( handle );
    return( 1 );

exit:
    psa_destroy_key( handle );
    return( 0 );
}

int exercise_cipher_setup( psa_key_type_t key_type,
                           const unsigned char *key_bytes,
                           size_t key_length,
                           psa_algorithm_t alg,
                           psa_cipher_operation_t *operation,
                           psa_status_t *status )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );
    PSA_ASSERT( psa_import_key( &attributes, key_bytes, key_length,
                                &handle ) );

    *status = psa_cipher_encrypt_setup( operation, handle, alg );
    /* Whether setup succeeded or failed, abort must succeed. */
    PSA_ASSERT( psa_cipher_abort( operation ) );
    /* If setup failed, reproduce the failure, so that the caller can
     * test the resulting state of the operation object. */
    if( *status != PSA_SUCCESS )
    {
        TEST_EQUAL( psa_cipher_encrypt_setup( operation, handle, alg ),
                    *status );
    }

    psa_destroy_key( handle );
    return( 1 );

exit:
    psa_destroy_key( handle );
    return( 0 );
}

static int exercise_mac_key( psa_key_handle_t handle,
                             psa_key_usage_t usage,
                             psa_algorithm_t alg )
{
    psa_mac_operation_t operation = PSA_MAC_OPERATION_INIT;
    const unsigned char input[] = "foo";
    unsigned char mac[PSA_MAC_MAX_SIZE] = {0};
    size_t mac_length = sizeof( mac );

    if( usage & PSA_KEY_USAGE_SIGN_HASH )
    {
        PSA_ASSERT( psa_mac_sign_setup( &operation,
                                        handle, alg ) );
        PSA_ASSERT( psa_mac_update( &operation,
                                    input, sizeof( input ) ) );
        PSA_ASSERT( psa_mac_sign_finish( &operation,
                                         mac, sizeof( mac ),
                                         &mac_length ) );
    }

    if( usage & PSA_KEY_USAGE_VERIFY_HASH )
    {
        psa_status_t verify_status =
            ( usage & PSA_KEY_USAGE_SIGN_HASH ?
              PSA_SUCCESS :
              PSA_ERROR_INVALID_SIGNATURE );
        PSA_ASSERT( psa_mac_verify_setup( &operation,
                                          handle, alg ) );
        PSA_ASSERT( psa_mac_update( &operation,
                                    input, sizeof( input ) ) );
        TEST_EQUAL( psa_mac_verify_finish( &operation, mac, mac_length ),
                    verify_status );
    }

    return( 1 );

exit:
    psa_mac_abort( &operation );
    return( 0 );
}

static int exercise_cipher_key( psa_key_handle_t handle,
                                psa_key_usage_t usage,
                                psa_algorithm_t alg )
{
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    unsigned char iv[16] = {0};
    size_t iv_length = sizeof( iv );
    const unsigned char plaintext[16] = "Hello, world...";
    unsigned char ciphertext[32] = "(wabblewebblewibblewobblewubble)";
    size_t ciphertext_length = sizeof( ciphertext );
    unsigned char decrypted[sizeof( ciphertext )];
    size_t part_length;

    if( usage & PSA_KEY_USAGE_ENCRYPT )
    {
        PSA_ASSERT( psa_cipher_encrypt_setup( &operation,
                                              handle, alg ) );
        PSA_ASSERT( psa_cipher_generate_iv( &operation,
                                            iv, sizeof( iv ),
                                            &iv_length ) );
        PSA_ASSERT( psa_cipher_update( &operation,
                                       plaintext, sizeof( plaintext ),
                                       ciphertext, sizeof( ciphertext ),
                                       &ciphertext_length ) );
        PSA_ASSERT( psa_cipher_finish( &operation,
                                       ciphertext + ciphertext_length,
                                       sizeof( ciphertext ) - ciphertext_length,
                                       &part_length ) );
        ciphertext_length += part_length;
    }

    if( usage & PSA_KEY_USAGE_DECRYPT )
    {
        psa_status_t status;
        int maybe_invalid_padding = 0;
        if( ! ( usage & PSA_KEY_USAGE_ENCRYPT ) )
        {
            psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
            PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
            /* This should be PSA_CIPHER_GET_IV_SIZE but the API doesn't
             * have this macro yet. */
            iv_length = PSA_BLOCK_CIPHER_BLOCK_SIZE(
                psa_get_key_type( &attributes ) );
            maybe_invalid_padding = ! PSA_ALG_IS_STREAM_CIPHER( alg );
        }
        PSA_ASSERT( psa_cipher_decrypt_setup( &operation,
                                              handle, alg ) );
        PSA_ASSERT( psa_cipher_set_iv( &operation,
                                       iv, iv_length ) );
        PSA_ASSERT( psa_cipher_update( &operation,
                                       ciphertext, ciphertext_length,
                                       decrypted, sizeof( decrypted ),
                                       &part_length ) );
        status = psa_cipher_finish( &operation,
                                    decrypted + part_length,
                                    sizeof( decrypted ) - part_length,
                                    &part_length );
        /* For a stream cipher, all inputs are valid. For a block cipher,
         * if the input is some aribtrary data rather than an actual
         ciphertext, a padding error is likely.  */
        if( maybe_invalid_padding )
            TEST_ASSERT( status == PSA_SUCCESS ||
                         status == PSA_ERROR_INVALID_PADDING );
        else
            PSA_ASSERT( status );
    }

    return( 1 );

exit:
    psa_cipher_abort( &operation );
    return( 0 );
}

static int exercise_aead_key( psa_key_handle_t handle,
                              psa_key_usage_t usage,
                              psa_algorithm_t alg )
{
    unsigned char nonce[16] = {0};
    size_t nonce_length = sizeof( nonce );
    unsigned char plaintext[16] = "Hello, world...";
    unsigned char ciphertext[48] = "(wabblewebblewibblewobblewubble)";
    size_t ciphertext_length = sizeof( ciphertext );
    size_t plaintext_length = sizeof( ciphertext );

    if( usage & PSA_KEY_USAGE_ENCRYPT )
    {
        PSA_ASSERT( psa_aead_encrypt( handle, alg,
                                      nonce, nonce_length,
                                      NULL, 0,
                                      plaintext, sizeof( plaintext ),
                                      ciphertext, sizeof( ciphertext ),
                                      &ciphertext_length ) );
    }

    if( usage & PSA_KEY_USAGE_DECRYPT )
    {
        psa_status_t verify_status =
            ( usage & PSA_KEY_USAGE_ENCRYPT ?
              PSA_SUCCESS :
              PSA_ERROR_INVALID_SIGNATURE );
        TEST_EQUAL( psa_aead_decrypt( handle, alg,
                                      nonce, nonce_length,
                                      NULL, 0,
                                      ciphertext, ciphertext_length,
                                      plaintext, sizeof( plaintext ),
                                      &plaintext_length ),
                    verify_status );
    }

    return( 1 );

exit:
    return( 0 );
}

static int exercise_signature_key( psa_key_handle_t handle,
                                   psa_key_usage_t usage,
                                   psa_algorithm_t alg )
{
    unsigned char payload[PSA_HASH_MAX_SIZE] = {1};
    size_t payload_length = 16;
    unsigned char signature[PSA_SIGNATURE_MAX_SIZE] = {0};
    size_t signature_length = sizeof( signature );
    psa_algorithm_t hash_alg = PSA_ALG_SIGN_GET_HASH( alg );

    /* If the policy allows signing with any hash, just pick one. */
    if( PSA_ALG_IS_HASH_AND_SIGN( alg ) && hash_alg == PSA_ALG_ANY_HASH )
    {
#if defined(KNOWN_SUPPORTED_HASH_ALG)
        hash_alg = KNOWN_SUPPORTED_HASH_ALG;
        alg ^= PSA_ALG_ANY_HASH ^ hash_alg;
#else
        test_fail( "No hash algorithm for hash-and-sign testing", __LINE__, __FILE__ );
        return( 1 );
#endif
    }

    if( usage & PSA_KEY_USAGE_SIGN_HASH )
    {
        /* Some algorithms require the payload to have the size of
         * the hash encoded in the algorithm. Use this input size
         * even for algorithms that allow other input sizes. */
        if( hash_alg != 0 )
            payload_length = PSA_HASH_SIZE( hash_alg );
        PSA_ASSERT( psa_sign_hash( handle, alg,
                                   payload, payload_length,
                                   signature, sizeof( signature ),
                                   &signature_length ) );
    }

    if( usage & PSA_KEY_USAGE_VERIFY_HASH )
    {
        psa_status_t verify_status =
            ( usage & PSA_KEY_USAGE_SIGN_HASH ?
              PSA_SUCCESS :
              PSA_ERROR_INVALID_SIGNATURE );
        TEST_EQUAL( psa_verify_hash( handle, alg,
                                     payload, payload_length,
                                     signature, signature_length ),
                    verify_status );
    }

    return( 1 );

exit:
    return( 0 );
}

static int exercise_asymmetric_encryption_key( psa_key_handle_t handle,
                                               psa_key_usage_t usage,
                                               psa_algorithm_t alg )
{
    unsigned char plaintext[256] = "Hello, world...";
    unsigned char ciphertext[256] = "(wabblewebblewibblewobblewubble)";
    size_t ciphertext_length = sizeof( ciphertext );
    size_t plaintext_length = 16;

    if( usage & PSA_KEY_USAGE_ENCRYPT )
    {
        PSA_ASSERT( psa_asymmetric_encrypt( handle, alg,
                                            plaintext, plaintext_length,
                                            NULL, 0,
                                            ciphertext, sizeof( ciphertext ),
                                            &ciphertext_length ) );
    }

    if( usage & PSA_KEY_USAGE_DECRYPT )
    {
        psa_status_t status =
            psa_asymmetric_decrypt( handle, alg,
                                    ciphertext, ciphertext_length,
                                    NULL, 0,
                                    plaintext, sizeof( plaintext ),
                                    &plaintext_length );
        TEST_ASSERT( status == PSA_SUCCESS ||
                     ( ( usage & PSA_KEY_USAGE_ENCRYPT ) == 0 &&
                       ( status == PSA_ERROR_INVALID_ARGUMENT ||
                         status == PSA_ERROR_INVALID_PADDING ) ) );
    }

    return( 1 );

exit:
    return( 0 );
}

static int setup_key_derivation_wrap( psa_key_derivation_operation_t* operation,
                                      psa_key_handle_t handle,
                                      psa_algorithm_t alg,
                                      unsigned char* input1, size_t input1_length,
                                      unsigned char* input2, size_t input2_length,
                                      size_t capacity )
{
    PSA_ASSERT( psa_key_derivation_setup( operation, alg ) );
    if( PSA_ALG_IS_HKDF( alg ) )
    {
        PSA_ASSERT( psa_key_derivation_input_bytes( operation,
                                                    PSA_KEY_DERIVATION_INPUT_SALT,
                                                    input1, input1_length ) );
        PSA_ASSERT( psa_key_derivation_input_key( operation,
                                                  PSA_KEY_DERIVATION_INPUT_SECRET,
                                                  handle ) );
        PSA_ASSERT( psa_key_derivation_input_bytes( operation,
                                                    PSA_KEY_DERIVATION_INPUT_INFO,
                                                    input2,
                                                    input2_length ) );
    }
    else if( PSA_ALG_IS_TLS12_PRF( alg ) ||
             PSA_ALG_IS_TLS12_PSK_TO_MS( alg ) )
    {
        PSA_ASSERT( psa_key_derivation_input_bytes( operation,
                                                    PSA_KEY_DERIVATION_INPUT_SEED,
                                                    input1, input1_length ) );
        PSA_ASSERT( psa_key_derivation_input_key( operation,
                                                  PSA_KEY_DERIVATION_INPUT_SECRET,
                                                  handle ) );
        PSA_ASSERT( psa_key_derivation_input_bytes( operation,
                                                    PSA_KEY_DERIVATION_INPUT_LABEL,
                                                    input2, input2_length ) );
    }
    else
    {
        TEST_ASSERT( ! "Key derivation algorithm not supported" );
    }

    if( capacity != SIZE_MAX )
        PSA_ASSERT( psa_key_derivation_set_capacity( operation, capacity ) );

    return( 1 );

exit:
    return( 0 );
}


static int exercise_key_derivation_key( psa_key_handle_t handle,
                                        psa_key_usage_t usage,
                                        psa_algorithm_t alg )
{
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    unsigned char input1[] = "Input 1";
    size_t input1_length = sizeof( input1 );
    unsigned char input2[] = "Input 2";
    size_t input2_length = sizeof( input2 );
    unsigned char output[1];
    size_t capacity = sizeof( output );

    if( usage & PSA_KEY_USAGE_DERIVE )
    {
        if( !setup_key_derivation_wrap( &operation, handle, alg,
                                        input1, input1_length,
                                        input2, input2_length, capacity ) )
            goto exit;

        PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                     output,
                                                     capacity ) );
        PSA_ASSERT( psa_key_derivation_abort( &operation ) );
    }

    return( 1 );

exit:
    return( 0 );
}

/* We need two keys to exercise key agreement. Exercise the
 * private key against its own public key. */
static psa_status_t key_agreement_with_self(
    psa_key_derivation_operation_t *operation,
    psa_key_handle_t handle )
{
    psa_key_type_t private_key_type;
    psa_key_type_t public_key_type;
    size_t key_bits;
    uint8_t *public_key = NULL;
    size_t public_key_length;
    /* Return GENERIC_ERROR if something other than the final call to
     * psa_key_derivation_key_agreement fails. This isn't fully satisfactory,
     * but it's good enough: callers will report it as a failed test anyway. */
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    private_key_type = psa_get_key_type( &attributes );
    key_bits = psa_get_key_bits( &attributes );
    public_key_type = PSA_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR( private_key_type );
    public_key_length = PSA_KEY_EXPORT_MAX_SIZE( public_key_type, key_bits );
    ASSERT_ALLOC( public_key, public_key_length );
    PSA_ASSERT( psa_export_public_key( handle,
                                       public_key, public_key_length,
                                       &public_key_length ) );

    status = psa_key_derivation_key_agreement(
        operation, PSA_KEY_DERIVATION_INPUT_SECRET, handle,
        public_key, public_key_length );
exit:
    mbedtls_free( public_key );
    psa_reset_key_attributes( &attributes );
    return( status );
}

/* We need two keys to exercise key agreement. Exercise the
 * private key against its own public key. */
static psa_status_t raw_key_agreement_with_self( psa_algorithm_t alg,
                                                 psa_key_handle_t handle )
{
    psa_key_type_t private_key_type;
    psa_key_type_t public_key_type;
    size_t key_bits;
    uint8_t *public_key = NULL;
    size_t public_key_length;
    uint8_t output[1024];
    size_t output_length;
    /* Return GENERIC_ERROR if something other than the final call to
     * psa_key_derivation_key_agreement fails. This isn't fully satisfactory,
     * but it's good enough: callers will report it as a failed test anyway. */
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    private_key_type = psa_get_key_type( &attributes );
    key_bits = psa_get_key_bits( &attributes );
    public_key_type = PSA_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR( private_key_type );
    public_key_length = PSA_KEY_EXPORT_MAX_SIZE( public_key_type, key_bits );
    ASSERT_ALLOC( public_key, public_key_length );
    PSA_ASSERT( psa_export_public_key( handle,
                                       public_key, public_key_length,
                                       &public_key_length ) );

    status = psa_raw_key_agreement( alg, handle,
                                    public_key, public_key_length,
                                    output, sizeof( output ), &output_length );
exit:
    mbedtls_free( public_key );
    psa_reset_key_attributes( &attributes );
    return( status );
}

static int exercise_raw_key_agreement_key( psa_key_handle_t handle,
                                           psa_key_usage_t usage,
                                           psa_algorithm_t alg )
{
    int ok = 0;

    if( usage & PSA_KEY_USAGE_DERIVE )
    {
        /* We need two keys to exercise key agreement. Exercise the
         * private key against its own public key. */
        PSA_ASSERT( raw_key_agreement_with_self( alg, handle ) );
    }
    ok = 1;

exit:
    return( ok );
}

static int exercise_key_agreement_key( psa_key_handle_t handle,
                                       psa_key_usage_t usage,
                                       psa_algorithm_t alg )
{
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    unsigned char output[1];
    int ok = 0;

    if( usage & PSA_KEY_USAGE_DERIVE )
    {
        /* We need two keys to exercise key agreement. Exercise the
         * private key against its own public key. */
        PSA_ASSERT( psa_key_derivation_setup( &operation, alg ) );
        PSA_ASSERT( key_agreement_with_self( &operation, handle ) );
        PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                     output,
                                                     sizeof( output ) ) );
        PSA_ASSERT( psa_key_derivation_abort( &operation ) );
    }
    ok = 1;

exit:
    return( ok );
}

int asn1_skip_integer( unsigned char **p, const unsigned char *end,
                       size_t min_bits, size_t max_bits,
                       int must_be_odd )
{
    size_t len;
    size_t actual_bits;
    unsigned char msb;
    TEST_EQUAL( mbedtls_asn1_get_tag( p, end, &len,
                                      MBEDTLS_ASN1_INTEGER ),
                0 );

    /* Check if the retrieved length doesn't extend the actual buffer's size.
     * It is assumed here, that end >= p, which validates casting to size_t. */
    TEST_ASSERT( len <= (size_t)( end - *p) );

    /* Tolerate a slight departure from DER encoding:
     * - 0 may be represented by an empty string or a 1-byte string.
     * - The sign bit may be used as a value bit. */
    if( ( len == 1 && ( *p )[0] == 0 ) ||
        ( len > 1 && ( *p )[0] == 0 && ( ( *p )[1] & 0x80 ) != 0 ) )
    {
        ++( *p );
        --len;
    }
    if( min_bits == 0 && len == 0 )
        return( 1 );
    msb = ( *p )[0];
    TEST_ASSERT( msb != 0 );
    actual_bits = 8 * ( len - 1 );
    while( msb != 0 )
    {
        msb >>= 1;
        ++actual_bits;
    }
    TEST_ASSERT( actual_bits >= min_bits );
    TEST_ASSERT( actual_bits <= max_bits );
    if( must_be_odd )
        TEST_ASSERT( ( ( *p )[len-1] & 1 ) != 0 );
    *p += len;
    return( 1 );
exit:
    return( 0 );
}

static int exported_key_sanity_check( psa_key_type_t type, size_t bits,
                                      uint8_t *exported, size_t exported_length )
{
    if( PSA_KEY_TYPE_IS_UNSTRUCTURED( type ) )
        TEST_EQUAL( exported_length, ( bits + 7 ) / 8 );
    else
        TEST_ASSERT( exported_length <= PSA_KEY_EXPORT_MAX_SIZE( type, bits ) );

#if defined(MBEDTLS_DES_C)
    if( type == PSA_KEY_TYPE_DES )
    {
        /* Check the parity bits. */
        unsigned i;
        for( i = 0; i < bits / 8; i++ )
        {
            unsigned bit_count = 0;
            unsigned m;
            for( m = 1; m <= 0x100; m <<= 1 )
            {
                if( exported[i] & m )
                    ++bit_count;
            }
            TEST_ASSERT( bit_count % 2 != 0 );
        }
    }
    else
#endif

#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_PK_PARSE_C)
    if( type == PSA_KEY_TYPE_RSA_KEY_PAIR )
    {
        uint8_t *p = exported;
        uint8_t *end = exported + exported_length;
        size_t len;
        /*   RSAPrivateKey ::= SEQUENCE {
         *       version             INTEGER,  -- must be 0
         *       modulus             INTEGER,  -- n
         *       publicExponent      INTEGER,  -- e
         *       privateExponent     INTEGER,  -- d
         *       prime1              INTEGER,  -- p
         *       prime2              INTEGER,  -- q
         *       exponent1           INTEGER,  -- d mod (p-1)
         *       exponent2           INTEGER,  -- d mod (q-1)
         *       coefficient         INTEGER,  -- (inverse of q) mod p
         *   }
         */
        TEST_EQUAL( mbedtls_asn1_get_tag( &p, end, &len,
                                          MBEDTLS_ASN1_SEQUENCE |
                                          MBEDTLS_ASN1_CONSTRUCTED ), 0 );
        TEST_EQUAL( p + len, end );
        if( ! asn1_skip_integer( &p, end, 0, 0, 0 ) )
            goto exit;
        if( ! asn1_skip_integer( &p, end, bits, bits, 1 ) )
            goto exit;
        if( ! asn1_skip_integer( &p, end, 2, bits, 1 ) )
            goto exit;
        /* Require d to be at least half the size of n. */
        if( ! asn1_skip_integer( &p, end, bits / 2, bits, 1 ) )
            goto exit;
        /* Require p and q to be at most half the size of n, rounded up. */
        if( ! asn1_skip_integer( &p, end, bits / 2, bits / 2 + 1, 1 ) )
            goto exit;
        if( ! asn1_skip_integer( &p, end, bits / 2, bits / 2 + 1, 1 ) )
            goto exit;
        if( ! asn1_skip_integer( &p, end, 1, bits / 2 + 1, 0 ) )
            goto exit;
        if( ! asn1_skip_integer( &p, end, 1, bits / 2 + 1, 0 ) )
            goto exit;
        if( ! asn1_skip_integer( &p, end, 1, bits / 2 + 1, 0 ) )
            goto exit;
        TEST_EQUAL( p, end );
    }
    else
#endif /* MBEDTLS_RSA_C */

#if defined(MBEDTLS_ECP_C)
    if( PSA_KEY_TYPE_IS_ECC_KEY_PAIR( type ) )
    {
        /* Just the secret value */
        TEST_EQUAL( exported_length, PSA_BITS_TO_BYTES( bits ) );
    }
    else
#endif /* MBEDTLS_ECP_C */

    if( PSA_KEY_TYPE_IS_PUBLIC_KEY( type ) )
    {
        uint8_t *p = exported;
        uint8_t *end = exported + exported_length;
#if defined(MBEDTLS_RSA_C)
        if( type == PSA_KEY_TYPE_RSA_PUBLIC_KEY )
        {
            size_t len;
            /*   RSAPublicKey ::= SEQUENCE {
             *      modulus            INTEGER,    -- n
             *      publicExponent     INTEGER  }  -- e
             */
            TEST_EQUAL( mbedtls_asn1_get_tag( &p, end, &len,
                                              MBEDTLS_ASN1_SEQUENCE |
                                              MBEDTLS_ASN1_CONSTRUCTED ),
                        0 );
            TEST_EQUAL( p + len, end );
            if( ! asn1_skip_integer( &p, end, bits, bits, 1 ) )
                goto exit;
            if( ! asn1_skip_integer( &p, end, 2, bits, 1 ) )
                goto exit;
            TEST_EQUAL( p, end );
        }
        else
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
        if( PSA_KEY_TYPE_IS_ECC_PUBLIC_KEY( type ) )
        {
            /* The representation of an ECC public key is:
             *      - The byte 0x04;
             *      - `x_P` as a `ceiling(m/8)`-byte string, big-endian;
             *      - `y_P` as a `ceiling(m/8)`-byte string, big-endian;
             *      - where m is the bit size associated with the curve.
             */
            TEST_EQUAL( p + 1 + 2 * PSA_BITS_TO_BYTES( bits ), end );
            TEST_EQUAL( p[0], 4 );
        }
        else
#endif /* MBEDTLS_ECP_C */
        {
            char message[47];
            mbedtls_snprintf( message, sizeof( message ),
                              "No sanity check for public key type=0x%08lx",
                              (unsigned long) type );
            test_fail( message, __LINE__, __FILE__ );
            (void) p;
            (void) end;
            return( 0 );
        }
    }
    else

    {
        /* No sanity checks for other types */
    }

    return( 1 );

exit:
    return( 0 );
}

static int exercise_export_key( psa_key_handle_t handle,
                                psa_key_usage_t usage )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    uint8_t *exported = NULL;
    size_t exported_size = 0;
    size_t exported_length = 0;
    int ok = 0;

    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );

    if( ( usage & PSA_KEY_USAGE_EXPORT ) == 0 &&
        ! PSA_KEY_TYPE_IS_PUBLIC_KEY( psa_get_key_type( &attributes ) ) )
    {
        TEST_EQUAL( psa_export_key( handle, NULL, 0, &exported_length ),
                    PSA_ERROR_NOT_PERMITTED );
        ok = 1;
        goto exit;
    }

    exported_size = PSA_KEY_EXPORT_MAX_SIZE( psa_get_key_type( &attributes ),
                                             psa_get_key_bits( &attributes ) );
    ASSERT_ALLOC( exported, exported_size );

    PSA_ASSERT( psa_export_key( handle,
                                exported, exported_size,
                                &exported_length ) );
    ok = exported_key_sanity_check( psa_get_key_type( &attributes ),
                                    psa_get_key_bits( &attributes ),
                                    exported, exported_length );

exit:
    mbedtls_free( exported );
    psa_reset_key_attributes( &attributes );
    return( ok );
}

static int exercise_export_public_key( psa_key_handle_t handle )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_type_t public_type;
    uint8_t *exported = NULL;
    size_t exported_size = 0;
    size_t exported_length = 0;
    int ok = 0;

    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    if( ! PSA_KEY_TYPE_IS_ASYMMETRIC( psa_get_key_type( &attributes ) ) )
    {
        TEST_EQUAL( psa_export_public_key( handle, NULL, 0, &exported_length ),
                    PSA_ERROR_INVALID_ARGUMENT );
        return( 1 );
    }

    public_type = PSA_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR(
        psa_get_key_type( &attributes ) );
    exported_size = PSA_KEY_EXPORT_MAX_SIZE( public_type,
                                             psa_get_key_bits( &attributes ) );
    ASSERT_ALLOC( exported, exported_size );

    PSA_ASSERT( psa_export_public_key( handle,
                                       exported, exported_size,
                                       &exported_length ) );
    ok = exported_key_sanity_check( public_type,
                                    psa_get_key_bits( &attributes ),
                                    exported, exported_length );

exit:
    mbedtls_free( exported );
    psa_reset_key_attributes( &attributes );
    return( ok );
}

/** Do smoke tests on a key.
 *
 * Perform one of each operation indicated by \p alg (decrypt/encrypt,
 * sign/verify, or derivation) that is permitted according to \p usage.
 * \p usage and \p alg should correspond to the expected policy on the
 * key.
 *
 * Export the key if permitted by \p usage, and check that the output
 * looks sensible. If \p usage forbids export, check that
 * \p psa_export_key correctly rejects the attempt. If the key is
 * asymmetric, also check \p psa_export_public_key.
 *
 * If the key fails the tests, this function calls the test framework's
 * `test_fail` function and returns false. Otherwise this function returns
 * true. Therefore it should be used as follows:
 * ```
 * if( ! exercise_key( ... ) ) goto exit;
 * ```
 *
 * \param handle    The key to exercise. It should be capable of performing
 *                  \p alg.
 * \param usage     The usage flags to assume.
 * \param alg       The algorithm to exercise.
 *
 * \retval 0 The key failed the smoke tests.
 * \retval 1 The key passed the smoke tests.
 */
static int exercise_key( psa_key_handle_t handle,
                         psa_key_usage_t usage,
                         psa_algorithm_t alg )
{
    int ok;

    if( ! check_key_attributes_sanity( handle ) )
        return( 0 );

    if( alg == 0 )
        ok = 1; /* If no algorihm, do nothing (used for raw data "keys"). */
    else if( PSA_ALG_IS_MAC( alg ) )
        ok = exercise_mac_key( handle, usage, alg );
    else if( PSA_ALG_IS_CIPHER( alg ) )
        ok = exercise_cipher_key( handle, usage, alg );
    else if( PSA_ALG_IS_AEAD( alg ) )
        ok = exercise_aead_key( handle, usage, alg );
    else if( PSA_ALG_IS_SIGN( alg ) )
        ok = exercise_signature_key( handle, usage, alg );
    else if( PSA_ALG_IS_ASYMMETRIC_ENCRYPTION( alg ) )
        ok = exercise_asymmetric_encryption_key( handle, usage, alg );
    else if( PSA_ALG_IS_KEY_DERIVATION( alg ) )
        ok = exercise_key_derivation_key( handle, usage, alg );
    else if( PSA_ALG_IS_RAW_KEY_AGREEMENT( alg ) )
        ok = exercise_raw_key_agreement_key( handle, usage, alg );
    else if( PSA_ALG_IS_KEY_AGREEMENT( alg ) )
        ok = exercise_key_agreement_key( handle, usage, alg );
    else
    {
        char message[40];
        mbedtls_snprintf( message, sizeof( message ),
                          "No code to exercise alg=0x%08lx",
                          (unsigned long) alg );
        test_fail( message, __LINE__, __FILE__ );
        ok = 0;
    }

    ok = ok && exercise_export_key( handle, usage );
    ok = ok && exercise_export_public_key( handle );

    return( ok );
}

static psa_key_usage_t usage_to_exercise( psa_key_type_t type,
                                          psa_algorithm_t alg )
{
    if( PSA_ALG_IS_MAC( alg ) || PSA_ALG_IS_SIGN( alg ) )
    {
        return( PSA_KEY_TYPE_IS_PUBLIC_KEY( type ) ?
                PSA_KEY_USAGE_VERIFY_HASH :
                PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH );
    }
    else if( PSA_ALG_IS_CIPHER( alg ) || PSA_ALG_IS_AEAD( alg ) ||
             PSA_ALG_IS_ASYMMETRIC_ENCRYPTION( alg ) )
    {
        return( PSA_KEY_TYPE_IS_PUBLIC_KEY( type ) ?
                PSA_KEY_USAGE_ENCRYPT :
                PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT );
    }
    else if( PSA_ALG_IS_KEY_DERIVATION( alg ) ||
             PSA_ALG_IS_KEY_AGREEMENT( alg ) )
    {
        return( PSA_KEY_USAGE_DERIVE );
    }
    else
    {
        return( 0 );
    }

}

static int test_operations_on_invalid_handle( psa_key_handle_t handle )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    uint8_t buffer[1];
    size_t length;
    int ok = 0;

    psa_set_key_id( &attributes, 0x6964 );
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT );
    psa_set_key_algorithm( &attributes, PSA_ALG_CTR );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_AES );
    TEST_EQUAL( psa_get_key_attributes( handle, &attributes ),
                PSA_ERROR_INVALID_HANDLE );
    TEST_EQUAL( psa_get_key_id( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_lifetime( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_usage_flags( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_algorithm( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_type( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_bits( &attributes ), 0 );

    TEST_EQUAL( psa_export_key( handle,
                                buffer, sizeof( buffer ), &length ),
                PSA_ERROR_INVALID_HANDLE );
    TEST_EQUAL( psa_export_public_key( handle,
                                       buffer, sizeof( buffer ), &length ),
                PSA_ERROR_INVALID_HANDLE );

    ok = 1;

exit:
    psa_reset_key_attributes( &attributes );
    return( ok );
}

/* Assert that a key isn't reported as having a slot number. */
#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
#define ASSERT_NO_SLOT_NUMBER( attributes )                             \
    do                                                                  \
    {                                                                   \
        psa_key_slot_number_t ASSERT_NO_SLOT_NUMBER_slot_number;        \
        TEST_EQUAL( psa_get_key_slot_number(                            \
                        attributes,                                     \
                        &ASSERT_NO_SLOT_NUMBER_slot_number ),           \
                    PSA_ERROR_INVALID_ARGUMENT );                       \
    }                                                                   \
    while( 0 )
#else /* MBEDTLS_PSA_CRYPTO_SE_C */
#define ASSERT_NO_SLOT_NUMBER( attributes )     \
    ( (void) 0 )
#endif /* MBEDTLS_PSA_CRYPTO_SE_C */

/* An overapproximation of the amount of storage needed for a key of the
 * given type and with the given content. The API doesn't make it easy
 * to find a good value for the size. The current implementation doesn't
 * care about the value anyway. */
#define KEY_BITS_FROM_DATA( type, data )        \
    ( data )->len

typedef enum {
    IMPORT_KEY = 0,
    GENERATE_KEY = 1,
    DERIVE_KEY = 2
} generate_method;

#line 1241 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_static_checks( )
{
    size_t max_truncated_mac_size =
        PSA_ALG_MAC_TRUNCATION_MASK >> PSA_MAC_TRUNCATION_OFFSET;

    /* Check that the length for a truncated MAC always fits in the algorithm
     * encoding. The shifted mask is the maximum truncated value. The
     * untruncated algorithm may be one byte larger. */
    TEST_ASSERT( PSA_MAC_MAX_SIZE <= 1 + max_truncated_mac_size );

#if defined(MBEDTLS_TEST_DEPRECATED)
    /* Check deprecated constants. */
    TEST_EQUAL( PSA_ERROR_UNKNOWN_ERROR, PSA_ERROR_GENERIC_ERROR );
    TEST_EQUAL( PSA_ERROR_OCCUPIED_SLOT, PSA_ERROR_ALREADY_EXISTS );
    TEST_EQUAL( PSA_ERROR_EMPTY_SLOT, PSA_ERROR_DOES_NOT_EXIST );
    TEST_EQUAL( PSA_ERROR_INSUFFICIENT_CAPACITY, PSA_ERROR_INSUFFICIENT_DATA );
    TEST_EQUAL( PSA_ERROR_TAMPERING_DETECTED, PSA_ERROR_CORRUPTION_DETECTED );
    TEST_EQUAL( PSA_KEY_USAGE_SIGN, PSA_KEY_USAGE_SIGN_HASH );
    TEST_EQUAL( PSA_KEY_USAGE_VERIFY, PSA_KEY_USAGE_VERIFY_HASH );
    TEST_EQUAL( PSA_ASYMMETRIC_SIGNATURE_MAX_SIZE, PSA_SIGNATURE_MAX_SIZE );

    TEST_EQUAL( PSA_ECC_CURVE_SECP160K1, PSA_ECC_CURVE_SECP_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP192K1, PSA_ECC_CURVE_SECP_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP224K1, PSA_ECC_CURVE_SECP_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP256K1, PSA_ECC_CURVE_SECP_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP160R1, PSA_ECC_CURVE_SECP_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP192R1, PSA_ECC_CURVE_SECP_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP224R1, PSA_ECC_CURVE_SECP_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP256R1, PSA_ECC_CURVE_SECP_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP384R1, PSA_ECC_CURVE_SECP_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP521R1, PSA_ECC_CURVE_SECP_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECP160R2, PSA_ECC_CURVE_SECP_R2 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT163K1, PSA_ECC_CURVE_SECT_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT233K1, PSA_ECC_CURVE_SECT_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT239K1, PSA_ECC_CURVE_SECT_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT283K1, PSA_ECC_CURVE_SECT_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT409K1, PSA_ECC_CURVE_SECT_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT571K1, PSA_ECC_CURVE_SECT_K1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT163R1, PSA_ECC_CURVE_SECT_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT193R1, PSA_ECC_CURVE_SECT_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT233R1, PSA_ECC_CURVE_SECT_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT283R1, PSA_ECC_CURVE_SECT_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT409R1, PSA_ECC_CURVE_SECT_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT571R1, PSA_ECC_CURVE_SECT_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT163R2, PSA_ECC_CURVE_SECT_R2 );
    TEST_EQUAL( PSA_ECC_CURVE_SECT193R2, PSA_ECC_CURVE_SECT_R2 );
    TEST_EQUAL( PSA_ECC_CURVE_BRAINPOOL_P256R1, PSA_ECC_CURVE_BRAINPOOL_P_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_BRAINPOOL_P384R1, PSA_ECC_CURVE_BRAINPOOL_P_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_BRAINPOOL_P512R1, PSA_ECC_CURVE_BRAINPOOL_P_R1 );
    TEST_EQUAL( PSA_ECC_CURVE_CURVE25519, PSA_ECC_CURVE_MONTGOMERY );
    TEST_EQUAL( PSA_ECC_CURVE_CURVE448, PSA_ECC_CURVE_MONTGOMERY );

    TEST_EQUAL( PSA_DH_GROUP_FFDHE2048, PSA_DH_GROUP_RFC7919 );
    TEST_EQUAL( PSA_DH_GROUP_FFDHE3072, PSA_DH_GROUP_RFC7919 );
    TEST_EQUAL( PSA_DH_GROUP_FFDHE4096, PSA_DH_GROUP_RFC7919 );
    TEST_EQUAL( PSA_DH_GROUP_FFDHE6144, PSA_DH_GROUP_RFC7919 );
    TEST_EQUAL( PSA_DH_GROUP_FFDHE8192, PSA_DH_GROUP_RFC7919 );
#endif
exit:
    ;
}

void test_static_checks_wrapper( void ** params )
{
    (void)params;

    test_static_checks(  );
}
#line 1303 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_attributes_set_get( int id_arg, int lifetime_arg,
                         int usage_flags_arg, int alg_arg,
                         int type_arg, int bits_arg )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_id_t id = id_arg;
    psa_key_lifetime_t lifetime = lifetime_arg;
    psa_key_usage_t usage_flags = usage_flags_arg;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t type = type_arg;
    size_t bits = bits_arg;

    TEST_EQUAL( psa_get_key_id( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_lifetime( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_usage_flags( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_algorithm( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_type( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_bits( &attributes ), 0 );

    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_usage_flags( &attributes, usage_flags );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );
    psa_set_key_bits( &attributes, bits );

    TEST_EQUAL( psa_get_key_id( &attributes ), id );
    TEST_EQUAL( psa_get_key_lifetime( &attributes ), lifetime );
    TEST_EQUAL( psa_get_key_usage_flags( &attributes ), usage_flags );
    TEST_EQUAL( psa_get_key_algorithm( &attributes ), alg );
    TEST_EQUAL( psa_get_key_type( &attributes ), type );
    TEST_EQUAL( psa_get_key_bits( &attributes ), bits );

    psa_reset_key_attributes( &attributes );

    TEST_EQUAL( psa_get_key_id( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_lifetime( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_usage_flags( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_algorithm( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_type( &attributes ), 0 );
    TEST_EQUAL( psa_get_key_bits( &attributes ), 0 );
exit:
    ;
}

void test_attributes_set_get_wrapper( void ** params )
{

    test_attributes_set_get( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ) );
}
#line 1348 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_persistence_attributes( int id1_arg, int lifetime_arg, int id2_arg,
                             int expected_id_arg, int expected_lifetime_arg )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_id_t id1 = id1_arg;
    psa_key_lifetime_t lifetime = lifetime_arg;
    psa_key_id_t id2 = id2_arg;
    psa_key_id_t expected_id = expected_id_arg;
    psa_key_lifetime_t expected_lifetime = expected_lifetime_arg;

    if( id1_arg != -1 )
        psa_set_key_id( &attributes, id1 );
    if( lifetime_arg != -1 )
        psa_set_key_lifetime( &attributes, lifetime );
    if( id2_arg != -1 )
        psa_set_key_id( &attributes, id2 );

    TEST_EQUAL( psa_get_key_id( &attributes ), expected_id );
    TEST_EQUAL( psa_get_key_lifetime( &attributes ), expected_lifetime );
exit:
    ;
}

void test_persistence_attributes_wrapper( void ** params )
{

    test_persistence_attributes( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
#line 1371 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_slot_number_attribute( )
{
    psa_key_slot_number_t slot_number = 0xdeadbeef;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    /* Initially, there is no slot number. */
    TEST_EQUAL( psa_get_key_slot_number( &attributes, &slot_number ),
                PSA_ERROR_INVALID_ARGUMENT );

    /* Test setting a slot number. */
    psa_set_key_slot_number( &attributes, 0 );
    PSA_ASSERT( psa_get_key_slot_number( &attributes, &slot_number ) );
    TEST_EQUAL( slot_number, 0 );

    /* Test changing the slot number. */
    psa_set_key_slot_number( &attributes, 42 );
    PSA_ASSERT( psa_get_key_slot_number( &attributes, &slot_number ) );
    TEST_EQUAL( slot_number, 42 );

    /* Test clearing the slot number. */
    psa_clear_key_slot_number( &attributes );
    TEST_EQUAL( psa_get_key_slot_number( &attributes, &slot_number ),
                PSA_ERROR_INVALID_ARGUMENT );

    /* Clearing again should have no effect. */
    psa_clear_key_slot_number( &attributes );
    TEST_EQUAL( psa_get_key_slot_number( &attributes, &slot_number ),
                PSA_ERROR_INVALID_ARGUMENT );

    /* Test that reset clears the slot number. */
    psa_set_key_slot_number( &attributes, 42 );
    PSA_ASSERT( psa_get_key_slot_number( &attributes, &slot_number ) );
    TEST_EQUAL( slot_number, 42 );
    psa_reset_key_attributes( &attributes );
    TEST_EQUAL( psa_get_key_slot_number( &attributes, &slot_number ),
                PSA_ERROR_INVALID_ARGUMENT );
exit:
    ;
}

void test_slot_number_attribute_wrapper( void ** params )
{
    (void)params;

    test_slot_number_attribute(  );
}
#endif /* MBEDTLS_PSA_CRYPTO_SE_C */
#line 1411 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_with_policy( int type_arg,
                         int usage_arg, int alg_arg,
                         int expected_status_arg )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t handle = 0;
    psa_key_type_t type = type_arg;
    psa_key_usage_t usage = usage_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    const uint8_t key_material[16] = {0};
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_type( &attributes, type );
    psa_set_key_usage_flags( &attributes, usage );
    psa_set_key_algorithm( &attributes, alg );

    status = psa_import_key( &attributes,
                             key_material, sizeof( key_material ),
                             &handle );
    TEST_EQUAL( status, expected_status );
    if( status != PSA_SUCCESS )
        goto exit;

    PSA_ASSERT( psa_get_key_attributes( handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_type( &got_attributes ), type );
    TEST_EQUAL( psa_get_key_usage_flags( &got_attributes ), usage );
    TEST_EQUAL( psa_get_key_algorithm( &got_attributes ), alg );
    ASSERT_NO_SLOT_NUMBER( &got_attributes );

    PSA_ASSERT( psa_destroy_key( handle ) );
    test_operations_on_invalid_handle( handle );

exit:
    psa_destroy_key( handle );
    psa_reset_key_attributes( &got_attributes );
    PSA_DONE( );
}

void test_import_with_policy_wrapper( void ** params )
{

    test_import_with_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ) );
}
#line 1455 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_with_data( data_t *data, int type_arg,
                       int attr_bits_arg,
                       int expected_status_arg )
{
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t handle = 0;
    psa_key_type_t type = type_arg;
    size_t attr_bits = attr_bits_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_type( &attributes, type );
    psa_set_key_bits( &attributes, attr_bits );

    status = psa_import_key( &attributes, data->x, data->len, &handle );
    TEST_EQUAL( status, expected_status );
    if( status != PSA_SUCCESS )
        goto exit;

    PSA_ASSERT( psa_get_key_attributes( handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_type( &got_attributes ), type );
    if( attr_bits != 0 )
        TEST_EQUAL( attr_bits, psa_get_key_bits( &got_attributes ) );
    ASSERT_NO_SLOT_NUMBER( &got_attributes );

    PSA_ASSERT( psa_destroy_key( handle ) );
    test_operations_on_invalid_handle( handle );

exit:
    psa_destroy_key( handle );
    psa_reset_key_attributes( &got_attributes );
    PSA_DONE( );
}

void test_import_with_data_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_import_with_data( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 1494 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_large_key( int type_arg, int byte_size_arg,
                       int expected_status_arg )
{
    psa_key_type_t type = type_arg;
    size_t byte_size = byte_size_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t expected_status = expected_status_arg;
    psa_key_handle_t handle = 0;
    psa_status_t status;
    uint8_t *buffer = NULL;
    size_t buffer_size = byte_size + 1;
    size_t n;

    /* It would be better to skip the test than fail it if the allocation
     * fails, but the test framework doesn't support this yet. */
    ASSERT_ALLOC( buffer, buffer_size );
    memset( buffer, 'K', byte_size );

    PSA_ASSERT( psa_crypto_init( ) );

    /* Try importing the key */
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_type( &attributes, type );
    status = psa_import_key( &attributes, buffer, byte_size, &handle );
    TEST_EQUAL( status, expected_status );

    if( status == PSA_SUCCESS )
    {
        PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
        TEST_EQUAL( psa_get_key_type( &attributes ), type );
        TEST_EQUAL( psa_get_key_bits( &attributes ),
                    PSA_BYTES_TO_BITS( byte_size ) );
        ASSERT_NO_SLOT_NUMBER( &attributes );
        memset( buffer, 0, byte_size + 1 );
        PSA_ASSERT( psa_export_key( handle, buffer, byte_size, &n ) );
        for( n = 0; n < byte_size; n++ )
            TEST_EQUAL( buffer[n], 'K' );
        for( n = byte_size; n < buffer_size; n++ )
            TEST_EQUAL( buffer[n], 0 );
    }

exit:
    psa_destroy_key( handle );
    PSA_DONE( );
    mbedtls_free( buffer );
}

void test_import_large_key_wrapper( void ** params )
{

    test_import_large_key( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 1543 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_rsa_made_up( int bits_arg, int keypair, int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    size_t bits = bits_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_status_t status;
    psa_key_type_t type =
        keypair ? PSA_KEY_TYPE_RSA_KEY_PAIR : PSA_KEY_TYPE_RSA_PUBLIC_KEY;
    size_t buffer_size = /* Slight overapproximations */
        keypair ? bits * 9 / 16 + 80 : bits / 8 + 20;
    unsigned char *buffer = NULL;
    unsigned char *p;
    int ret;
    size_t length;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );
    ASSERT_ALLOC( buffer, buffer_size );

    TEST_ASSERT( ( ret = construct_fake_rsa_key( buffer, buffer_size, &p,
                                                 bits, keypair ) ) >= 0 );
    length = ret;

    /* Try importing the key */
    psa_set_key_type( &attributes, type );
    status = psa_import_key( &attributes, p, length, &handle );
    TEST_EQUAL( status, expected_status );

    if( status == PSA_SUCCESS )
        PSA_ASSERT( psa_destroy_key( handle ) );

exit:
    mbedtls_free( buffer );
    PSA_DONE( );
}

void test_import_rsa_made_up_wrapper( void ** params )
{

    test_import_rsa_made_up( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 1581 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_export( data_t *data,
                    int type_arg,
                    int usage_arg, int alg_arg,
                    int expected_bits,
                    int export_size_delta,
                    int expected_export_status_arg,
                    int canonical_input )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t type = type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_export_status = expected_export_status_arg;
    psa_status_t status;
    unsigned char *exported = NULL;
    unsigned char *reexported = NULL;
    size_t export_size;
    size_t exported_length = INVALID_EXPORT_LENGTH;
    size_t reexported_length;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;

    export_size = (ptrdiff_t) data->len + export_size_delta;
    ASSERT_ALLOC( exported, export_size );
    if( ! canonical_input )
        ASSERT_ALLOC( reexported, export_size );
    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, usage_arg );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );

    /* Import the key */
    PSA_ASSERT( psa_import_key( &attributes, data->x, data->len, &handle ) );

    /* Test the key information */
    PSA_ASSERT( psa_get_key_attributes( handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_type( &got_attributes ), type );
    TEST_EQUAL( psa_get_key_bits( &got_attributes ), (size_t) expected_bits );
    ASSERT_NO_SLOT_NUMBER( &got_attributes );

    /* Export the key */
    status = psa_export_key( handle,
                             exported, export_size,
                             &exported_length );
    TEST_EQUAL( status, expected_export_status );

    /* The exported length must be set by psa_export_key() to a value between 0
     * and export_size. On errors, the exported length must be 0. */
    TEST_ASSERT( exported_length != INVALID_EXPORT_LENGTH );
    TEST_ASSERT( status == PSA_SUCCESS || exported_length == 0 );
    TEST_ASSERT( exported_length <= export_size );

    TEST_ASSERT( mem_is_char( exported + exported_length, 0,
                              export_size - exported_length ) );
    if( status != PSA_SUCCESS )
    {
        TEST_EQUAL( exported_length, 0 );
        goto destroy;
    }

    if( ! exercise_export_key( handle, usage_arg ) )
        goto exit;

    if( canonical_input )
        ASSERT_COMPARE( data->x, data->len, exported, exported_length );
    else
    {
        psa_key_handle_t handle2;
        PSA_ASSERT( psa_import_key( &attributes, exported, exported_length,
                                    &handle2 ) );
        PSA_ASSERT( psa_export_key( handle2,
                                    reexported,
                                    export_size,
                                    &reexported_length ) );
        ASSERT_COMPARE( exported, exported_length,
                        reexported, reexported_length );
        PSA_ASSERT( psa_close_key( handle2 ) );
    }
    TEST_ASSERT( exported_length <= PSA_KEY_EXPORT_MAX_SIZE( type, psa_get_key_bits( &got_attributes ) ) );

destroy:
    /* Destroy the key */
    PSA_ASSERT( psa_destroy_key( handle ) );
    test_operations_on_invalid_handle( handle );

exit:
    mbedtls_free( exported );
    mbedtls_free( reexported );
    psa_reset_key_attributes( &got_attributes );
    PSA_DONE( );
}

void test_import_export_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_import_export( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ), *( (int *) params[7] ), *( (int *) params[8] ) );
}
#line 1675 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_export_public_key( data_t *data,
                               int type_arg,
                               int alg_arg,
                               int export_size_delta,
                               int expected_export_status_arg,
                               data_t *expected_public_key )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t type = type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_export_status = expected_export_status_arg;
    psa_status_t status;
    unsigned char *exported = NULL;
    size_t export_size = expected_public_key->len + export_size_delta;
    size_t exported_length = INVALID_EXPORT_LENGTH;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );

    /* Import the key */
    PSA_ASSERT( psa_import_key( &attributes, data->x, data->len, &handle ) );

    /* Export the public key */
    ASSERT_ALLOC( exported, export_size );
    status = psa_export_public_key( handle,
                                    exported, export_size,
                                    &exported_length );
    TEST_EQUAL( status, expected_export_status );
    if( status == PSA_SUCCESS )
    {
        psa_key_type_t public_type = PSA_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR( type );
        size_t bits;
        PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
        bits = psa_get_key_bits( &attributes );
        TEST_ASSERT( expected_public_key->len <=
                     PSA_KEY_EXPORT_MAX_SIZE( public_type, bits ) );
        ASSERT_COMPARE( expected_public_key->x, expected_public_key->len,
                        exported, exported_length );
    }

exit:
    mbedtls_free( exported );
    psa_destroy_key( handle );
    psa_reset_key_attributes( &attributes );
    PSA_DONE( );
}

void test_import_export_public_key_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_import_export_public_key( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), &data6 );
}
#line 1728 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_import_and_exercise_key( data_t *data,
                              int type_arg,
                              int bits_arg,
                              int alg_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t type = type_arg;
    size_t bits = bits_arg;
    psa_algorithm_t alg = alg_arg;
    psa_key_usage_t usage = usage_to_exercise( type, alg );
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, usage );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );

    /* Import the key */
    PSA_ASSERT( psa_import_key( &attributes, data->x, data->len, &handle ) );

    /* Test the key information */
    PSA_ASSERT( psa_get_key_attributes( handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_type( &got_attributes ), type );
    TEST_EQUAL( psa_get_key_bits( &got_attributes ), bits );

    /* Do something with the key according to its type and permitted usage. */
    if( ! exercise_key( handle, usage, alg ) )
        goto exit;

    PSA_ASSERT( psa_destroy_key( handle ) );
    test_operations_on_invalid_handle( handle );

exit:
    psa_destroy_key( handle );
    psa_reset_key_attributes( &got_attributes );
    PSA_DONE( );
}

void test_import_and_exercise_key_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_import_and_exercise_key( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 1770 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_effective_key_attributes( int type_arg, int expected_type_arg,
                               int bits_arg, int expected_bits_arg,
                               int usage_arg, int expected_usage_arg,
                               int alg_arg, int expected_alg_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = type_arg;
    psa_key_type_t expected_key_type = expected_type_arg;
    size_t bits = bits_arg;
    size_t expected_bits = expected_bits_arg;
    psa_algorithm_t alg = alg_arg;
    psa_algorithm_t expected_alg = expected_alg_arg;
    psa_key_usage_t usage = usage_arg;
    psa_key_usage_t expected_usage = expected_usage_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, usage );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );
    psa_set_key_bits( &attributes, bits );

    PSA_ASSERT( psa_generate_key( &attributes, &handle ) );
    psa_reset_key_attributes( &attributes );

    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    TEST_EQUAL( psa_get_key_type( &attributes ), expected_key_type );
    TEST_EQUAL( psa_get_key_bits( &attributes ), expected_bits );
    TEST_EQUAL( psa_get_key_usage_flags( &attributes ), expected_usage );
    TEST_EQUAL( psa_get_key_algorithm( &attributes ), expected_alg );

exit:
    psa_destroy_key( handle );
    psa_reset_key_attributes( &attributes );
    PSA_DONE( );
}

void test_effective_key_attributes_wrapper( void ** params )
{

    test_effective_key_attributes( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ), *( (int *) params[7] ) );
}
#line 1810 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_check_key_policy( int type_arg, int bits_arg,
                       int usage_arg, int alg_arg )
{
    test_effective_key_attributes( type_arg, type_arg, bits_arg, bits_arg,
                                   usage_arg, usage_arg, alg_arg, alg_arg );
    goto exit;
exit:
    ;
}

void test_check_key_policy_wrapper( void ** params )
{

    test_check_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ) );
}
#line 1820 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_key_attributes_init( )
{
    /* Test each valid way of initializing the object, except for `= {0}`, as
     * Clang 5 complains when `-Wmissing-field-initializers` is used, even
     * though it's OK by the C standard. We could test for this, but we'd need
     * to supress the Clang warning for the test. */
    psa_key_attributes_t func = psa_key_attributes_init( );
    psa_key_attributes_t init = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t zero;

    memset( &zero, 0, sizeof( zero ) );

    TEST_EQUAL( psa_get_key_lifetime( &func ), PSA_KEY_LIFETIME_VOLATILE );
    TEST_EQUAL( psa_get_key_lifetime( &init ), PSA_KEY_LIFETIME_VOLATILE );
    TEST_EQUAL( psa_get_key_lifetime( &zero ), PSA_KEY_LIFETIME_VOLATILE );

    TEST_EQUAL( psa_get_key_type( &func ), 0 );
    TEST_EQUAL( psa_get_key_type( &init ), 0 );
    TEST_EQUAL( psa_get_key_type( &zero ), 0 );

    TEST_EQUAL( psa_get_key_bits( &func ), 0 );
    TEST_EQUAL( psa_get_key_bits( &init ), 0 );
    TEST_EQUAL( psa_get_key_bits( &zero ), 0 );

    TEST_EQUAL( psa_get_key_usage_flags( &func ), 0 );
    TEST_EQUAL( psa_get_key_usage_flags( &init ), 0 );
    TEST_EQUAL( psa_get_key_usage_flags( &zero ), 0 );

    TEST_EQUAL( psa_get_key_algorithm( &func ), 0 );
    TEST_EQUAL( psa_get_key_algorithm( &init ), 0 );
    TEST_EQUAL( psa_get_key_algorithm( &zero ), 0 );
exit:
    ;
}

void test_key_attributes_init_wrapper( void ** params )
{
    (void)params;

    test_key_attributes_init(  );
}
#line 1855 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_mac_key_policy( int policy_usage,
                     int policy_alg,
                     int key_type,
                     data_t *key_data,
                     int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_mac_operation_t operation = PSA_MAC_OPERATION_INIT;
    psa_status_t status;
    unsigned char mac[PSA_MAC_MAX_SIZE];

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    status = psa_mac_sign_setup( &operation, handle, exercise_alg );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_SIGN_HASH ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );
    psa_mac_abort( &operation );

    memset( mac, 0, sizeof( mac ) );
    status = psa_mac_verify_setup( &operation, handle, exercise_alg );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_VERIFY_HASH ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_mac_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_mac_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_mac_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ) );
}
#line 1900 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_key_policy( int policy_usage,
                        int policy_alg,
                        int key_type,
                        data_t *key_data,
                        int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    status = psa_cipher_encrypt_setup( &operation, handle, exercise_alg );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_ENCRYPT ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );
    psa_cipher_abort( &operation );

    status = psa_cipher_decrypt_setup( &operation, handle, exercise_alg );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_DECRYPT ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_cipher_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_cipher_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ) );
}
#line 1943 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_aead_key_policy( int policy_usage,
                      int policy_alg,
                      int key_type,
                      data_t *key_data,
                      int nonce_length_arg,
                      int tag_length_arg,
                      int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t status;
    unsigned char nonce[16] = {0};
    size_t nonce_length = nonce_length_arg;
    unsigned char tag[16];
    size_t tag_length = tag_length_arg;
    size_t output_length;

    TEST_ASSERT( nonce_length <= sizeof( nonce ) );
    TEST_ASSERT( tag_length <= sizeof( tag ) );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    status = psa_aead_encrypt( handle, exercise_alg,
                               nonce, nonce_length,
                               NULL, 0,
                               NULL, 0,
                               tag, tag_length,
                               &output_length );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_ENCRYPT ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

    memset( tag, 0, sizeof( tag ) );
    status = psa_aead_decrypt( handle, exercise_alg,
                               nonce, nonce_length,
                               NULL, 0,
                               tag, tag_length,
                               NULL, 0,
                               &output_length );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_DECRYPT ) != 0 )
        TEST_EQUAL( status, PSA_ERROR_INVALID_SIGNATURE );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_aead_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_aead_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ), *( (int *) params[6] ), *( (int *) params[7] ) );
}
#line 2004 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_encryption_key_policy( int policy_usage,
                                       int policy_alg,
                                       int key_type,
                                       data_t *key_data,
                                       int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t status;
    size_t key_bits;
    size_t buffer_length;
    unsigned char *buffer = NULL;
    size_t output_length;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    key_bits = psa_get_key_bits( &attributes );
    buffer_length = PSA_ASYMMETRIC_ENCRYPT_OUTPUT_SIZE( key_type, key_bits,
                                                        exercise_alg );
    ASSERT_ALLOC( buffer, buffer_length );

    status = psa_asymmetric_encrypt( handle, exercise_alg,
                                     NULL, 0,
                                     NULL, 0,
                                     buffer, buffer_length,
                                     &output_length );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_ENCRYPT ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

    if( buffer_length != 0 )
        memset( buffer, 0, buffer_length );
    status = psa_asymmetric_decrypt( handle, exercise_alg,
                                     buffer, buffer_length,
                                     NULL, 0,
                                     buffer, buffer_length,
                                     &output_length );
    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_DECRYPT ) != 0 )
        TEST_EQUAL( status, PSA_ERROR_INVALID_PADDING );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_destroy_key( handle );
    psa_reset_key_attributes( &attributes );
    PSA_DONE( );
    mbedtls_free( buffer );
}

void test_asymmetric_encryption_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_asymmetric_encryption_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ) );
}
#line 2066 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_signature_key_policy( int policy_usage,
                                      int policy_alg,
                                      int key_type,
                                      data_t *key_data,
                                      int exercise_alg,
                                      int payload_length_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t status;
    unsigned char payload[PSA_HASH_MAX_SIZE] = {1};
    /* If `payload_length_arg > 0`, `exercise_alg` is supposed to be
     * compatible with the policy and `payload_length_arg` is supposed to be
     * a valid input length to sign. If `payload_length_arg <= 0`,
     * `exercise_alg` is supposed to be forbidden by the policy. */
    int compatible_alg = payload_length_arg > 0;
    size_t payload_length = compatible_alg ? payload_length_arg : 0;
    unsigned char signature[PSA_SIGNATURE_MAX_SIZE] = {0};
    size_t signature_length;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    status = psa_sign_hash( handle, exercise_alg,
                            payload, payload_length,
                            signature, sizeof( signature ),
                            &signature_length );
    if( compatible_alg && ( policy_usage & PSA_KEY_USAGE_SIGN_HASH ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

    memset( signature, 0, sizeof( signature ) );
    status = psa_verify_hash( handle, exercise_alg,
                              payload, payload_length,
                              signature, sizeof( signature ) );
    if( compatible_alg && ( policy_usage & PSA_KEY_USAGE_VERIFY_HASH ) != 0 )
        TEST_EQUAL( status, PSA_ERROR_INVALID_SIGNATURE );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_asymmetric_signature_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_asymmetric_signature_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ), *( (int *) params[6] ) );
}
#line 2120 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_key_policy( int policy_usage,
                        int policy_alg,
                        int key_type,
                        data_t *key_data,
                        int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_key_derivation_setup( &operation, exercise_alg ) );

    if( PSA_ALG_IS_TLS12_PRF( exercise_alg ) ||
            PSA_ALG_IS_TLS12_PSK_TO_MS( exercise_alg ) )
    {
        PSA_ASSERT( psa_key_derivation_input_bytes(
                                            &operation,
                                            PSA_KEY_DERIVATION_INPUT_SEED,
                                            (const uint8_t*) "", 0) );
    }

    status = psa_key_derivation_input_key( &operation,
                                           PSA_KEY_DERIVATION_INPUT_SECRET,
                                           handle );

    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_DERIVE ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_derive_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_derive_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ) );
}
#line 2169 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_agreement_key_policy( int policy_usage,
                           int policy_alg,
                           int key_type_arg,
                           data_t *key_data,
                           int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_type_t key_type = key_type_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_key_derivation_setup( &operation, exercise_alg ) );
    status = key_agreement_with_self( &operation, handle );

    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_DERIVE ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_agreement_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_agreement_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ) );
}
#line 2207 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_key_policy_alg2( int key_type_arg, data_t *key_data,
                      int usage_arg, int alg_arg, int alg2_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_usage_t usage = usage_arg;
    psa_algorithm_t alg = alg_arg;
    psa_algorithm_t alg2 = alg2_arg;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, usage );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_enrollment_algorithm( &attributes, alg2 );
    psa_set_key_type( &attributes, key_type );
    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_get_key_attributes( handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_usage_flags( &got_attributes ), usage );
    TEST_EQUAL( psa_get_key_algorithm( &got_attributes ), alg );
    TEST_EQUAL( psa_get_key_enrollment_algorithm( &got_attributes ), alg2 );

    if( ! exercise_key( handle, usage, alg ) )
        goto exit;
    if( ! exercise_key( handle, usage, alg2 ) )
        goto exit;

exit:
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_key_policy_alg2_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};

    test_key_policy_alg2( *( (int *) params[0] ), &data1, *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ) );
}
#line 2244 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_raw_agreement_key_policy( int policy_usage,
                               int policy_alg,
                               int key_type_arg,
                               data_t *key_data,
                               int exercise_alg )
{
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_type_t key_type = key_type_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, policy_usage );
    psa_set_key_algorithm( &attributes, policy_alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    status = raw_key_agreement_with_self( exercise_alg, handle );

    if( policy_alg == exercise_alg &&
        ( policy_usage & PSA_KEY_USAGE_DERIVE ) != 0 )
        PSA_ASSERT( status );
    else
        TEST_EQUAL( status, PSA_ERROR_NOT_PERMITTED );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_raw_agreement_key_policy_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_raw_agreement_key_policy( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ) );
}
#line 2281 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_copy_success( int source_usage_arg,
                   int source_alg_arg, int source_alg2_arg,
                   int type_arg, data_t *material,
                   int copy_attributes,
                   int target_usage_arg,
                   int target_alg_arg, int target_alg2_arg,
                   int expected_usage_arg,
                   int expected_alg_arg, int expected_alg2_arg )
{
    psa_key_attributes_t source_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t target_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_usage_t expected_usage = expected_usage_arg;
    psa_algorithm_t expected_alg = expected_alg_arg;
    psa_algorithm_t expected_alg2 = expected_alg2_arg;
    psa_key_handle_t source_handle = 0;
    psa_key_handle_t target_handle = 0;
    uint8_t *export_buffer = NULL;

    PSA_ASSERT( psa_crypto_init( ) );

    /* Prepare the source key. */
    psa_set_key_usage_flags( &source_attributes, source_usage_arg );
    psa_set_key_algorithm( &source_attributes, source_alg_arg );
    psa_set_key_enrollment_algorithm( &source_attributes, source_alg2_arg );
    psa_set_key_type( &source_attributes, type_arg );
    PSA_ASSERT( psa_import_key( &source_attributes,
                                material->x, material->len,
                                &source_handle ) );
    PSA_ASSERT( psa_get_key_attributes( source_handle, &source_attributes ) );

    /* Prepare the target attributes. */
    if( copy_attributes )
        target_attributes = source_attributes;
    if( target_usage_arg != -1 )
        psa_set_key_usage_flags( &target_attributes, target_usage_arg );
    if( target_alg_arg != -1 )
        psa_set_key_algorithm( &target_attributes, target_alg_arg );
    if( target_alg2_arg != -1 )
        psa_set_key_enrollment_algorithm( &target_attributes, target_alg2_arg );

    /* Copy the key. */
    PSA_ASSERT( psa_copy_key( source_handle,
                              &target_attributes, &target_handle ) );

    /* Destroy the source to ensure that this doesn't affect the target. */
    PSA_ASSERT( psa_destroy_key( source_handle ) );

    /* Test that the target slot has the expected content and policy. */
    PSA_ASSERT( psa_get_key_attributes( target_handle, &target_attributes ) );
    TEST_EQUAL( psa_get_key_type( &source_attributes ),
                psa_get_key_type( &target_attributes ) );
    TEST_EQUAL( psa_get_key_bits( &source_attributes ),
                psa_get_key_bits( &target_attributes ) );
    TEST_EQUAL( expected_usage, psa_get_key_usage_flags( &target_attributes ) );
    TEST_EQUAL( expected_alg, psa_get_key_algorithm( &target_attributes ) );
    TEST_EQUAL( expected_alg2,
                psa_get_key_enrollment_algorithm( &target_attributes ) );
    if( expected_usage & PSA_KEY_USAGE_EXPORT )
    {
        size_t length;
        ASSERT_ALLOC( export_buffer, material->len );
        PSA_ASSERT( psa_export_key( target_handle, export_buffer,
                                    material->len, &length ) );
        ASSERT_COMPARE( material->x, material->len,
                        export_buffer, length );
    }
    if( ! exercise_key( target_handle, expected_usage, expected_alg ) )
        goto exit;
    if( ! exercise_key( target_handle, expected_usage, expected_alg2 ) )
        goto exit;

    PSA_ASSERT( psa_close_key( target_handle ) );

exit:
    psa_reset_key_attributes( &source_attributes );
    psa_reset_key_attributes( &target_attributes );
    PSA_DONE( );
    mbedtls_free( export_buffer );
}

void test_copy_success_wrapper( void ** params )
{
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_copy_success( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), &data4, *( (int *) params[6] ), *( (int *) params[7] ), *( (int *) params[8] ), *( (int *) params[9] ), *( (int *) params[10] ), *( (int *) params[11] ), *( (int *) params[12] ) );
}
#line 2363 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_copy_fail( int source_usage_arg,
                int source_alg_arg, int source_alg2_arg,
                int type_arg, data_t *material,
                int target_type_arg, int target_bits_arg,
                int target_usage_arg,
                int target_alg_arg, int target_alg2_arg,
                int expected_status_arg )
{
    psa_key_attributes_t source_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t target_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t source_handle = 0;
    psa_key_handle_t target_handle = 0;

    PSA_ASSERT( psa_crypto_init( ) );

    /* Prepare the source key. */
    psa_set_key_usage_flags( &source_attributes, source_usage_arg );
    psa_set_key_algorithm( &source_attributes, source_alg_arg );
    psa_set_key_enrollment_algorithm( &source_attributes, source_alg2_arg );
    psa_set_key_type( &source_attributes, type_arg );
    PSA_ASSERT( psa_import_key( &source_attributes,
                                material->x, material->len,
                                &source_handle ) );

    /* Prepare the target attributes. */
    psa_set_key_type( &target_attributes, target_type_arg );
    psa_set_key_bits( &target_attributes, target_bits_arg );
    psa_set_key_usage_flags( &target_attributes, target_usage_arg );
    psa_set_key_algorithm( &target_attributes, target_alg_arg );
    psa_set_key_enrollment_algorithm( &target_attributes, target_alg2_arg );

    /* Try to copy the key. */
    TEST_EQUAL( psa_copy_key( source_handle,
                              &target_attributes, &target_handle ),
                expected_status_arg );

    PSA_ASSERT( psa_destroy_key( source_handle ) );

exit:
    psa_reset_key_attributes( &source_attributes );
    psa_reset_key_attributes( &target_attributes );
    PSA_DONE( );
}

void test_copy_fail_wrapper( void ** params )
{
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_copy_fail( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), &data4, *( (int *) params[6] ), *( (int *) params[7] ), *( (int *) params[8] ), *( (int *) params[9] ), *( (int *) params[10] ), *( (int *) params[11] ) );
}
#line 2409 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_operation_init( )
{
    const uint8_t input[1] = { 0 };
    /* Test each valid way of initializing the object, except for `= {0}`, as
     * Clang 5 complains when `-Wmissing-field-initializers` is used, even
     * though it's OK by the C standard. We could test for this, but we'd need
     * to supress the Clang warning for the test. */
    psa_hash_operation_t func = psa_hash_operation_init( );
    psa_hash_operation_t init = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t zero;

    memset( &zero, 0, sizeof( zero ) );

    /* A freshly-initialized hash operation should not be usable. */
    TEST_EQUAL( psa_hash_update( &func, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_hash_update( &init, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_hash_update( &zero, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );

    /* A default hash operation should be abortable without error. */
    PSA_ASSERT( psa_hash_abort( &func ) );
    PSA_ASSERT( psa_hash_abort( &init ) );
    PSA_ASSERT( psa_hash_abort( &zero ) );
exit:
    ;
}

void test_hash_operation_init_wrapper( void ** params )
{
    (void)params;

    test_hash_operation_init(  );
}
#line 2438 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_setup( int alg_arg,
                 int expected_status_arg )
{
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_hash_operation_t operation = PSA_HASH_OPERATION_INIT;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    status = psa_hash_setup( &operation, alg );
    TEST_EQUAL( status, expected_status );

    /* Whether setup succeeded or failed, abort must succeed. */
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* If setup failed, reproduce the failure, so as to
     * test the resulting state of the operation object. */
    if( status != PSA_SUCCESS )
        TEST_EQUAL( psa_hash_setup( &operation, alg ), status );

    /* Now the operation object should be reusable. */
#if defined(KNOWN_SUPPORTED_HASH_ALG)
    PSA_ASSERT( psa_hash_setup( &operation, KNOWN_SUPPORTED_HASH_ALG ) );
    PSA_ASSERT( psa_hash_abort( &operation ) );
#endif

exit:
    PSA_DONE( );
}

void test_hash_setup_wrapper( void ** params )
{

    test_hash_setup( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#line 2471 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_compute_fail( int alg_arg, data_t *input,
                        int output_size_arg, int expected_status_arg )
{
    psa_algorithm_t alg = alg_arg;
    uint8_t *output = NULL;
    size_t output_size = output_size_arg;
    size_t output_length = INVALID_EXPORT_LENGTH;
    psa_status_t expected_status = expected_status_arg;
    psa_status_t status;

    ASSERT_ALLOC( output, output_size );

    PSA_ASSERT( psa_crypto_init( ) );

    status = psa_hash_compute( alg, input->x, input->len,
                               output, output_size, &output_length );
    TEST_EQUAL( status, expected_status );
    TEST_ASSERT( output_length <= output_size );

exit:
    mbedtls_free( output );
    PSA_DONE( );
}

void test_hash_compute_fail_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};

    test_hash_compute_fail( *( (int *) params[0] ), &data1, *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 2497 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_compare_fail( int alg_arg, data_t *input,
                        data_t *reference_hash,
                        int expected_status_arg )
{
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    status = psa_hash_compare( alg, input->x, input->len,
                               reference_hash->x, reference_hash->len );
    TEST_EQUAL( status, expected_status );

exit:
    PSA_DONE( );
}

void test_hash_compare_fail_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_hash_compare_fail( *( (int *) params[0] ), &data1, &data3, *( (int *) params[5] ) );
}
#line 2517 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_compute_compare( int alg_arg, data_t *input,
                           data_t *expected_output )
{
    psa_algorithm_t alg = alg_arg;
    uint8_t output[PSA_HASH_MAX_SIZE + 1];
    size_t output_length = INVALID_EXPORT_LENGTH;
    size_t i;

    PSA_ASSERT( psa_crypto_init( ) );

    /* Compute with tight buffer */
    PSA_ASSERT( psa_hash_compute( alg, input->x, input->len,
                                  output, PSA_HASH_SIZE( alg ),
                                  &output_length ) );
    TEST_EQUAL( output_length, PSA_HASH_SIZE( alg ) );
    ASSERT_COMPARE( output, output_length,
                    expected_output->x, expected_output->len );

    /* Compute with larger buffer */
    PSA_ASSERT( psa_hash_compute( alg, input->x, input->len,
                                  output, sizeof( output ),
                                  &output_length ) );
    TEST_EQUAL( output_length, PSA_HASH_SIZE( alg ) );
    ASSERT_COMPARE( output, output_length,
                    expected_output->x, expected_output->len );

    /* Compare with correct hash */
    PSA_ASSERT( psa_hash_compare( alg, input->x, input->len,
                                  output, output_length ) );

    /* Compare with trailing garbage */
    TEST_EQUAL( psa_hash_compare( alg, input->x, input->len,
                                  output, output_length + 1 ),
                PSA_ERROR_INVALID_SIGNATURE );

    /* Compare with truncated hash */
    TEST_EQUAL( psa_hash_compare( alg, input->x, input->len,
                                  output, output_length - 1 ),
                PSA_ERROR_INVALID_SIGNATURE );

    /* Compare with corrupted value */
    for( i = 0; i < output_length; i++ )
    {
        test_set_step( i );
        output[i] ^= 1;
        TEST_EQUAL( psa_hash_compare( alg, input->x, input->len,
                                      output, output_length ),
                    PSA_ERROR_INVALID_SIGNATURE );
        output[i] ^= 1;
    }

exit:
    PSA_DONE( );
}

void test_hash_compute_compare_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};

    test_hash_compute_compare( *( (int *) params[0] ), &data1, &data3 );
}
#line 2574 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_bad_order( )
{
    psa_algorithm_t alg = PSA_ALG_SHA_256;
    unsigned char input[] = "";
    /* SHA-256 hash of an empty string */
    const unsigned char valid_hash[] = {
        0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14, 0x9a, 0xfb, 0xf4, 0xc8,
        0x99, 0x6f, 0xb9, 0x24, 0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
        0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55 };
    unsigned char hash[sizeof(valid_hash)] = { 0 };
    size_t hash_len;
    psa_hash_operation_t operation = PSA_HASH_OPERATION_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    /* Call setup twice in a row. */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    TEST_EQUAL( psa_hash_setup( &operation, alg ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call update without calling setup beforehand. */
    TEST_EQUAL( psa_hash_update( &operation, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call update after finish. */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    PSA_ASSERT( psa_hash_finish( &operation,
                                 hash, sizeof( hash ), &hash_len ) );
    TEST_EQUAL( psa_hash_update( &operation, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call verify without calling setup beforehand. */
    TEST_EQUAL( psa_hash_verify( &operation,
                                 valid_hash, sizeof( valid_hash ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call verify after finish. */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    PSA_ASSERT( psa_hash_finish( &operation,
                                 hash, sizeof( hash ), &hash_len ) );
    TEST_EQUAL( psa_hash_verify( &operation,
                                 valid_hash, sizeof( valid_hash ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call verify twice in a row. */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    PSA_ASSERT( psa_hash_verify( &operation,
                                 valid_hash, sizeof( valid_hash ) ) );
    TEST_EQUAL( psa_hash_verify( &operation,
                                 valid_hash, sizeof( valid_hash ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call finish without calling setup beforehand. */
    TEST_EQUAL( psa_hash_finish( &operation,
                                 hash, sizeof( hash ), &hash_len ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call finish twice in a row. */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    PSA_ASSERT( psa_hash_finish( &operation,
                                 hash, sizeof( hash ), &hash_len ) );
    TEST_EQUAL( psa_hash_finish( &operation,
                                 hash, sizeof( hash ), &hash_len ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

    /* Call finish after calling verify. */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    PSA_ASSERT( psa_hash_verify( &operation,
                                 valid_hash, sizeof( valid_hash ) ) );
    TEST_EQUAL( psa_hash_finish( &operation,
                                 hash, sizeof( hash ), &hash_len ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_hash_abort( &operation ) );

exit:
    PSA_DONE( );
}

void test_hash_bad_order_wrapper( void ** params )
{
    (void)params;

    test_hash_bad_order(  );
}
#if defined(MBEDTLS_SHA256_C)
#line 2662 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_verify_bad_args( )
{
    psa_algorithm_t alg = PSA_ALG_SHA_256;
    /* SHA-256 hash of an empty string with 2 extra bytes (0xaa and 0xbb)
     * appended to it */
    unsigned char hash[] = {
        0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14, 0x9a, 0xfb, 0xf4, 0xc8,
        0x99, 0x6f, 0xb9, 0x24, 0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
        0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55, 0xaa, 0xbb };
    size_t expected_size = PSA_HASH_SIZE( alg );
    psa_hash_operation_t operation = PSA_HASH_OPERATION_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    /* psa_hash_verify with a smaller hash than expected */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    TEST_EQUAL( psa_hash_verify( &operation, hash, expected_size - 1 ),
                PSA_ERROR_INVALID_SIGNATURE );

    /* psa_hash_verify with a non-matching hash */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    TEST_EQUAL( psa_hash_verify( &operation, hash + 1, expected_size ),
                PSA_ERROR_INVALID_SIGNATURE );

    /* psa_hash_verify with a hash longer than expected */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    TEST_EQUAL( psa_hash_verify( &operation, hash, sizeof( hash ) ),
                PSA_ERROR_INVALID_SIGNATURE );

exit:
    PSA_DONE( );
}

void test_hash_verify_bad_args_wrapper( void ** params )
{
    (void)params;

    test_hash_verify_bad_args(  );
}
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA256_C)
#line 2697 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_finish_bad_args( )
{
    psa_algorithm_t alg = PSA_ALG_SHA_256;
    unsigned char hash[PSA_HASH_MAX_SIZE];
    size_t expected_size = PSA_HASH_SIZE( alg );
    psa_hash_operation_t operation = PSA_HASH_OPERATION_INIT;
    size_t hash_len;

    PSA_ASSERT( psa_crypto_init( ) );

    /* psa_hash_finish with a smaller hash buffer than expected */
    PSA_ASSERT( psa_hash_setup( &operation, alg ) );
    TEST_EQUAL( psa_hash_finish( &operation,
                                 hash, expected_size - 1, &hash_len ),
                PSA_ERROR_BUFFER_TOO_SMALL );

exit:
    PSA_DONE( );
}

void test_hash_finish_bad_args_wrapper( void ** params )
{
    (void)params;

    test_hash_finish_bad_args(  );
}
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA256_C)
#line 2719 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_clone_source_state( )
{
    psa_algorithm_t alg = PSA_ALG_SHA_256;
    unsigned char hash[PSA_HASH_MAX_SIZE];
    psa_hash_operation_t op_source = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_init = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_setup = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_finished = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_aborted = PSA_HASH_OPERATION_INIT;
    size_t hash_len;

    PSA_ASSERT( psa_crypto_init( ) );
    PSA_ASSERT( psa_hash_setup( &op_source, alg ) );

    PSA_ASSERT( psa_hash_setup( &op_setup, alg ) );
    PSA_ASSERT( psa_hash_setup( &op_finished, alg ) );
    PSA_ASSERT( psa_hash_finish( &op_finished,
                                 hash, sizeof( hash ), &hash_len ) );
    PSA_ASSERT( psa_hash_setup( &op_aborted, alg ) );
    PSA_ASSERT( psa_hash_abort( &op_aborted ) );

    TEST_EQUAL( psa_hash_clone( &op_source, &op_setup ),
                PSA_ERROR_BAD_STATE );

    PSA_ASSERT( psa_hash_clone( &op_source, &op_init ) );
    PSA_ASSERT( psa_hash_finish( &op_init,
                                 hash, sizeof( hash ), &hash_len ) );
    PSA_ASSERT( psa_hash_clone( &op_source, &op_finished ) );
    PSA_ASSERT( psa_hash_finish( &op_finished,
                                 hash, sizeof( hash ), &hash_len ) );
    PSA_ASSERT( psa_hash_clone( &op_source, &op_aborted ) );
    PSA_ASSERT( psa_hash_finish( &op_aborted,
                                 hash, sizeof( hash ), &hash_len ) );

exit:
    psa_hash_abort( &op_source );
    psa_hash_abort( &op_init );
    psa_hash_abort( &op_setup );
    psa_hash_abort( &op_finished );
    psa_hash_abort( &op_aborted );
    PSA_DONE( );
}

void test_hash_clone_source_state_wrapper( void ** params )
{
    (void)params;

    test_hash_clone_source_state(  );
}
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA256_C)
#line 2764 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_hash_clone_target_state( )
{
    psa_algorithm_t alg = PSA_ALG_SHA_256;
    unsigned char hash[PSA_HASH_MAX_SIZE];
    psa_hash_operation_t op_init = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_setup = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_finished = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_aborted = PSA_HASH_OPERATION_INIT;
    psa_hash_operation_t op_target = PSA_HASH_OPERATION_INIT;
    size_t hash_len;

    PSA_ASSERT( psa_crypto_init( ) );

    PSA_ASSERT( psa_hash_setup( &op_setup, alg ) );
    PSA_ASSERT( psa_hash_setup( &op_finished, alg ) );
    PSA_ASSERT( psa_hash_finish( &op_finished,
                                 hash, sizeof( hash ), &hash_len ) );
    PSA_ASSERT( psa_hash_setup( &op_aborted, alg ) );
    PSA_ASSERT( psa_hash_abort( &op_aborted ) );

    PSA_ASSERT( psa_hash_clone( &op_setup, &op_target ) );
    PSA_ASSERT( psa_hash_finish( &op_target,
                                 hash, sizeof( hash ), &hash_len ) );

    TEST_EQUAL( psa_hash_clone( &op_init, &op_target ), PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_hash_clone( &op_finished, &op_target ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_hash_clone( &op_aborted, &op_target ),
                PSA_ERROR_BAD_STATE );

exit:
    psa_hash_abort( &op_target );
    psa_hash_abort( &op_init );
    psa_hash_abort( &op_setup );
    psa_hash_abort( &op_finished );
    psa_hash_abort( &op_aborted );
    PSA_DONE( );
}

void test_hash_clone_target_state_wrapper( void ** params )
{
    (void)params;

    test_hash_clone_target_state(  );
}
#endif /* MBEDTLS_SHA256_C */
#line 2805 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_mac_operation_init( )
{
    const uint8_t input[1] = { 0 };

    /* Test each valid way of initializing the object, except for `= {0}`, as
     * Clang 5 complains when `-Wmissing-field-initializers` is used, even
     * though it's OK by the C standard. We could test for this, but we'd need
     * to supress the Clang warning for the test. */
    psa_mac_operation_t func = psa_mac_operation_init( );
    psa_mac_operation_t init = PSA_MAC_OPERATION_INIT;
    psa_mac_operation_t zero;

    memset( &zero, 0, sizeof( zero ) );

    /* A freshly-initialized MAC operation should not be usable. */
    TEST_EQUAL( psa_mac_update( &func,
                                input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_mac_update( &init,
                                input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_mac_update( &zero,
                                input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );

    /* A default MAC operation should be abortable without error. */
    PSA_ASSERT( psa_mac_abort( &func ) );
    PSA_ASSERT( psa_mac_abort( &init ) );
    PSA_ASSERT( psa_mac_abort( &zero ) );
exit:
    ;
}

void test_mac_operation_init_wrapper( void ** params )
{
    (void)params;

    test_mac_operation_init(  );
}
#line 2838 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_mac_setup( int key_type_arg,
                data_t *key,
                int alg_arg,
                int expected_status_arg )
{
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_mac_operation_t operation = PSA_MAC_OPERATION_INIT;
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;
#if defined(KNOWN_SUPPORTED_MAC_ALG)
    const uint8_t smoke_test_key_data[16] = "kkkkkkkkkkkkkkkk";
#endif

    PSA_ASSERT( psa_crypto_init( ) );

    if( ! exercise_mac_setup( key_type, key->x, key->len, alg,
                              &operation, &status ) )
        goto exit;
    TEST_EQUAL( status, expected_status );

    /* The operation object should be reusable. */
#if defined(KNOWN_SUPPORTED_MAC_ALG)
    if( ! exercise_mac_setup( KNOWN_SUPPORTED_MAC_KEY_TYPE,
                              smoke_test_key_data,
                              sizeof( smoke_test_key_data ),
                              KNOWN_SUPPORTED_MAC_ALG,
                              &operation, &status ) )
        goto exit;
    TEST_EQUAL( status, PSA_SUCCESS );
#endif

exit:
    PSA_DONE( );
}

void test_mac_setup_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};

    test_mac_setup( *( (int *) params[0] ), &data1, *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 2876 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_mac_bad_order( )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = PSA_KEY_TYPE_HMAC;
    psa_algorithm_t alg = PSA_ALG_HMAC(PSA_ALG_SHA_256);
    const uint8_t key[] = {
        0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
        0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
        0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa };
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_mac_operation_t operation = PSA_MAC_OPERATION_INIT;
    uint8_t sign_mac[PSA_MAC_MAX_SIZE + 10] = { 0 };
    size_t sign_mac_length = 0;
    const uint8_t input[] = { 0xbb, 0xbb, 0xbb, 0xbb };
    const uint8_t verify_mac[] = {
        0x74, 0x65, 0x93, 0x8c, 0xeb, 0x1d, 0xb3, 0x76, 0x5a, 0x38, 0xe7, 0xdd,
        0x85, 0xc5, 0xad, 0x4f, 0x07, 0xe7, 0xd5, 0xb2, 0x64, 0xf0, 0x1a, 0x1a,
        0x2c, 0xf9, 0x18, 0xca, 0x59, 0x7e, 0x5d, 0xf6 };

    PSA_ASSERT( psa_crypto_init( ) );
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key, sizeof( key ), &handle ) );

    /* Call update without calling setup beforehand. */
    TEST_EQUAL( psa_mac_update( &operation, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call sign finish without calling setup beforehand. */
    TEST_EQUAL( psa_mac_sign_finish( &operation, sign_mac, sizeof( sign_mac ),
                                     &sign_mac_length),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call verify finish without calling setup beforehand. */
    TEST_EQUAL( psa_mac_verify_finish( &operation,
                                       verify_mac, sizeof( verify_mac ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call setup twice in a row. */
    PSA_ASSERT( psa_mac_sign_setup( &operation,
                                    handle, alg ) );
    TEST_EQUAL( psa_mac_sign_setup( &operation,
                                    handle, alg ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call update after sign finish. */
    PSA_ASSERT( psa_mac_sign_setup( &operation,
                                    handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation, input, sizeof( input ) ) );
    PSA_ASSERT( psa_mac_sign_finish( &operation,
                                     sign_mac, sizeof( sign_mac ),
                                     &sign_mac_length ) );
    TEST_EQUAL( psa_mac_update( &operation, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call update after verify finish. */
    PSA_ASSERT( psa_mac_verify_setup( &operation,
                                      handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation, input, sizeof( input ) ) );
    PSA_ASSERT( psa_mac_verify_finish( &operation,
                                       verify_mac, sizeof( verify_mac ) ) );
    TEST_EQUAL( psa_mac_update( &operation, input, sizeof( input ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call sign finish twice in a row. */
    PSA_ASSERT( psa_mac_sign_setup( &operation,
                                    handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation, input, sizeof( input ) ) );
    PSA_ASSERT( psa_mac_sign_finish( &operation,
                                     sign_mac, sizeof( sign_mac ),
                                     &sign_mac_length ) );
    TEST_EQUAL( psa_mac_sign_finish( &operation,
                                     sign_mac, sizeof( sign_mac ),
                                     &sign_mac_length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Call verify finish twice in a row. */
    PSA_ASSERT( psa_mac_verify_setup( &operation,
                                      handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation, input, sizeof( input ) ) );
    PSA_ASSERT( psa_mac_verify_finish( &operation,
                                       verify_mac, sizeof( verify_mac ) ) );
    TEST_EQUAL( psa_mac_verify_finish( &operation,
                                       verify_mac, sizeof( verify_mac ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Setup sign but try verify. */
    PSA_ASSERT( psa_mac_sign_setup( &operation,
                                    handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation, input, sizeof( input ) ) );
    TEST_EQUAL( psa_mac_verify_finish( &operation,
                                       verify_mac, sizeof( verify_mac ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    /* Setup verify but try sign. */
    PSA_ASSERT( psa_mac_verify_setup( &operation,
                                      handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation, input, sizeof( input ) ) );
    TEST_EQUAL( psa_mac_sign_finish( &operation,
                                     sign_mac, sizeof( sign_mac ),
                                     &sign_mac_length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_mac_abort( &operation ) );

    PSA_ASSERT( psa_destroy_key( handle ) );

exit:
    PSA_DONE( );
}

void test_mac_bad_order_wrapper( void ** params )
{
    (void)params;

    test_mac_bad_order(  );
}
#line 2999 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_mac_sign( int key_type_arg,
               data_t *key,
               int alg_arg,
               data_t *input,
               data_t *expected_mac )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_mac_operation_t operation = PSA_MAC_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    /* Leave a little extra room in the output buffer. At the end of the
     * test, we'll check that the implementation didn't overwrite onto
     * this extra room. */
    uint8_t actual_mac[PSA_MAC_MAX_SIZE + 10];
    size_t mac_buffer_size =
        PSA_MAC_FINAL_SIZE( key_type, PSA_BYTES_TO_BITS( key->len ), alg );
    size_t mac_length = 0;

    memset( actual_mac, '+', sizeof( actual_mac ) );
    TEST_ASSERT( mac_buffer_size <= PSA_MAC_MAX_SIZE );
    TEST_ASSERT( expected_mac->len <= mac_buffer_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    /* Calculate the MAC. */
    PSA_ASSERT( psa_mac_sign_setup( &operation,
                                    handle, alg ) );
    PSA_ASSERT( psa_mac_update( &operation,
                                input->x, input->len ) );
    PSA_ASSERT( psa_mac_sign_finish( &operation,
                                     actual_mac, mac_buffer_size,
                                     &mac_length ) );

    /* Compare with the expected value. */
    ASSERT_COMPARE( expected_mac->x, expected_mac->len,
                    actual_mac, mac_length );

    /* Verify that the end of the buffer is untouched. */
    TEST_ASSERT( mem_is_char( actual_mac + mac_length, '+',
                              sizeof( actual_mac ) - mac_length ) );

exit:
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_mac_sign_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_mac_sign( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6 );
}
#line 3054 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_mac_verify( int key_type_arg,
                 data_t *key,
                 int alg_arg,
                 data_t *input,
                 data_t *expected_mac )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_mac_operation_t operation = PSA_MAC_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    TEST_ASSERT( expected_mac->len <= PSA_MAC_MAX_SIZE );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_mac_verify_setup( &operation,
                                      handle, alg ) );
    PSA_ASSERT( psa_destroy_key( handle ) );
    PSA_ASSERT( psa_mac_update( &operation,
                                input->x, input->len ) );
    PSA_ASSERT( psa_mac_verify_finish( &operation,
                                       expected_mac->x,
                                       expected_mac->len ) );

exit:
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_mac_verify_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_mac_verify( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6 );
}
#line 3092 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_operation_init( )
{
    const uint8_t input[1] = { 0 };
    unsigned char output[1] = { 0 };
    size_t output_length;
    /* Test each valid way of initializing the object, except for `= {0}`, as
     * Clang 5 complains when `-Wmissing-field-initializers` is used, even
     * though it's OK by the C standard. We could test for this, but we'd need
     * to supress the Clang warning for the test. */
    psa_cipher_operation_t func = psa_cipher_operation_init( );
    psa_cipher_operation_t init = PSA_CIPHER_OPERATION_INIT;
    psa_cipher_operation_t zero;

    memset( &zero, 0, sizeof( zero ) );

    /* A freshly-initialized cipher operation should not be usable. */
    TEST_EQUAL( psa_cipher_update( &func,
                                   input, sizeof( input ),
                                   output, sizeof( output ),
                                   &output_length ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_cipher_update( &init,
                                   input, sizeof( input ),
                                   output, sizeof( output ),
                                   &output_length ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_cipher_update( &zero,
                                   input, sizeof( input ),
                                   output, sizeof( output ),
                                   &output_length ),
                PSA_ERROR_BAD_STATE );

    /* A default cipher operation should be abortable without error. */
    PSA_ASSERT( psa_cipher_abort( &func ) );
    PSA_ASSERT( psa_cipher_abort( &init ) );
    PSA_ASSERT( psa_cipher_abort( &zero ) );
exit:
    ;
}

void test_cipher_operation_init_wrapper( void ** params )
{
    (void)params;

    test_cipher_operation_init(  );
}
#line 3132 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_setup( int key_type_arg,
                   data_t *key,
                   int alg_arg,
                   int expected_status_arg )
{
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    psa_status_t status;
#if defined(KNOWN_SUPPORTED_MAC_ALG)
    const uint8_t smoke_test_key_data[16] = "kkkkkkkkkkkkkkkk";
#endif

    PSA_ASSERT( psa_crypto_init( ) );

    if( ! exercise_cipher_setup( key_type, key->x, key->len, alg,
                                 &operation, &status ) )
        goto exit;
    TEST_EQUAL( status, expected_status );

    /* The operation object should be reusable. */
#if defined(KNOWN_SUPPORTED_CIPHER_ALG)
    if( ! exercise_cipher_setup( KNOWN_SUPPORTED_CIPHER_KEY_TYPE,
                                 smoke_test_key_data,
                                 sizeof( smoke_test_key_data ),
                                 KNOWN_SUPPORTED_CIPHER_ALG,
                                 &operation, &status ) )
        goto exit;
    TEST_EQUAL( status, PSA_SUCCESS );
#endif

exit:
    PSA_DONE( );
}

void test_cipher_setup_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};

    test_cipher_setup( *( (int *) params[0] ), &data1, *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 3170 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_bad_order( )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = PSA_KEY_TYPE_AES;
    psa_algorithm_t alg = PSA_ALG_CBC_PKCS7;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    unsigned char iv[PSA_BLOCK_CIPHER_BLOCK_SIZE(PSA_KEY_TYPE_AES)] = { 0 };
    const uint8_t key[] = {
        0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
        0xaa, 0xaa, 0xaa, 0xaa };
    const uint8_t text[] = {
        0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
        0xbb, 0xbb, 0xbb, 0xbb };
    uint8_t buffer[PSA_BLOCK_CIPHER_BLOCK_SIZE(PSA_KEY_TYPE_AES)] = { 0 };
    size_t length = 0;

    PSA_ASSERT( psa_crypto_init( ) );
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );
    PSA_ASSERT( psa_import_key( &attributes, key, sizeof( key ), &handle ) );


    /* Call encrypt setup twice in a row. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    TEST_EQUAL( psa_cipher_encrypt_setup( &operation, handle, alg ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call decrypt setup twice in a row. */
    PSA_ASSERT( psa_cipher_decrypt_setup( &operation, handle, alg ) );
    TEST_EQUAL( psa_cipher_decrypt_setup( &operation, handle, alg ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Generate an IV without calling setup beforehand. */
    TEST_EQUAL( psa_cipher_generate_iv( &operation,
                                        buffer, sizeof( buffer ),
                                        &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Generate an IV twice in a row. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    PSA_ASSERT( psa_cipher_generate_iv( &operation,
                                        buffer, sizeof( buffer ),
                                        &length ) );
    TEST_EQUAL( psa_cipher_generate_iv( &operation,
                                        buffer, sizeof( buffer ),
                                        &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Generate an IV after it's already set. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    PSA_ASSERT( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ) );
    TEST_EQUAL( psa_cipher_generate_iv( &operation,
                                        buffer, sizeof( buffer ),
                                        &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Set an IV without calling setup beforehand. */
    TEST_EQUAL( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Set an IV after it's already set. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    PSA_ASSERT( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ) );
    TEST_EQUAL( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Set an IV after it's already generated. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    PSA_ASSERT( psa_cipher_generate_iv( &operation,
                                        buffer, sizeof( buffer ),
                                        &length ) );
    TEST_EQUAL( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call update without calling setup beforehand. */
    TEST_EQUAL( psa_cipher_update( &operation,
                                   text, sizeof( text ),
                                   buffer, sizeof( buffer ),
                                   &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call update without an IV where an IV is required. */
    TEST_EQUAL( psa_cipher_update( &operation,
                                   text, sizeof( text ),
                                   buffer, sizeof( buffer ),
                                   &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call update after finish. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    PSA_ASSERT( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ) );
    PSA_ASSERT( psa_cipher_finish( &operation,
                                   buffer, sizeof( buffer ), &length ) );
    TEST_EQUAL( psa_cipher_update( &operation,
                                   text, sizeof( text ),
                                   buffer, sizeof( buffer ),
                                   &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call finish without calling setup beforehand. */
    TEST_EQUAL( psa_cipher_finish( &operation,
                                   buffer, sizeof( buffer ), &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call finish without an IV where an IV is required. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    /* Not calling update means we are encrypting an empty buffer, which is OK
     * for cipher modes with padding. */
    TEST_EQUAL( psa_cipher_finish( &operation,
                                   buffer, sizeof( buffer ), &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    /* Call finish twice in a row. */
    PSA_ASSERT( psa_cipher_encrypt_setup( &operation, handle, alg ) );
    PSA_ASSERT( psa_cipher_set_iv( &operation,
                                   iv, sizeof( iv ) ) );
    PSA_ASSERT( psa_cipher_finish( &operation,
                                   buffer, sizeof( buffer ), &length ) );
    TEST_EQUAL( psa_cipher_finish( &operation,
                                   buffer, sizeof( buffer ), &length ),
                PSA_ERROR_BAD_STATE );
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    PSA_ASSERT( psa_destroy_key( handle ) );

exit:
    PSA_DONE( );
}

void test_cipher_bad_order_wrapper( void ** params )
{
    (void)params;

    test_cipher_bad_order(  );
}
#line 3322 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_encrypt( int alg_arg, int key_type_arg,
                     data_t *key, data_t *iv,
                     data_t *input, data_t *expected_output,
                     int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_status_t status;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    unsigned char *output = NULL;
    size_t output_buffer_size = 0;
    size_t function_output_length = 0;
    size_t total_output_length = 0;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_cipher_encrypt_setup( &operation,
                                          handle, alg ) );

    PSA_ASSERT( psa_cipher_set_iv( &operation, iv->x, iv->len ) );
    output_buffer_size = ( (size_t) input->len +
                           PSA_BLOCK_CIPHER_BLOCK_SIZE( key_type ) );
    ASSERT_ALLOC( output, output_buffer_size );

    PSA_ASSERT( psa_cipher_update( &operation,
                                   input->x, input->len,
                                   output, output_buffer_size,
                                   &function_output_length ) );
    total_output_length += function_output_length;
    status = psa_cipher_finish( &operation,
                                output + total_output_length,
                                output_buffer_size - total_output_length,
                                &function_output_length );
    total_output_length += function_output_length;

    TEST_EQUAL( status, expected_status );
    if( expected_status == PSA_SUCCESS )
    {
        PSA_ASSERT( psa_cipher_abort( &operation ) );
        ASSERT_COMPARE( expected_output->x, expected_output->len,
                        output, total_output_length );
    }

exit:
    mbedtls_free( output );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_encrypt_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_cipher_encrypt( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, &data8, *( (int *) params[10] ) );
}
#line 3382 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_encrypt_multipart( int alg_arg, int key_type_arg,
                               data_t *key, data_t *iv,
                               data_t *input,
                               int first_part_size_arg,
                               int output1_length_arg, int output2_length_arg,
                               data_t *expected_output )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t first_part_size = first_part_size_arg;
    size_t output1_length = output1_length_arg;
    size_t output2_length = output2_length_arg;
    unsigned char *output = NULL;
    size_t output_buffer_size = 0;
    size_t function_output_length = 0;
    size_t total_output_length = 0;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_cipher_encrypt_setup( &operation,
                                          handle, alg ) );

    PSA_ASSERT( psa_cipher_set_iv( &operation, iv->x, iv->len ) );
    output_buffer_size = ( (size_t) input->len +
                           PSA_BLOCK_CIPHER_BLOCK_SIZE( key_type ) );
    ASSERT_ALLOC( output, output_buffer_size );

    TEST_ASSERT( first_part_size <= input->len );
    PSA_ASSERT( psa_cipher_update( &operation, input->x, first_part_size,
                                   output, output_buffer_size,
                                   &function_output_length ) );
    TEST_ASSERT( function_output_length == output1_length );
    total_output_length += function_output_length;
    PSA_ASSERT( psa_cipher_update( &operation,
                                   input->x + first_part_size,
                                   input->len - first_part_size,
                                   output + total_output_length,
                                   output_buffer_size - total_output_length,
                                   &function_output_length ) );
    TEST_ASSERT( function_output_length == output2_length );
    total_output_length += function_output_length;
    PSA_ASSERT( psa_cipher_finish( &operation,
                                   output + total_output_length,
                                   output_buffer_size - total_output_length,
                                   &function_output_length ) );
    total_output_length += function_output_length;
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    ASSERT_COMPARE( expected_output->x, expected_output->len,
                    output, total_output_length );

exit:
    mbedtls_free( output );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_encrypt_multipart_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data11 = {(uint8_t *) params[11], *( (uint32_t *) params[12] )};

    test_cipher_encrypt_multipart( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, *( (int *) params[8] ), *( (int *) params[9] ), *( (int *) params[10] ), &data11 );
}
#line 3450 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_decrypt_multipart( int alg_arg, int key_type_arg,
                               data_t *key, data_t *iv,
                               data_t *input,
                               int first_part_size_arg,
                               int output1_length_arg, int output2_length_arg,
                               data_t *expected_output )
{
    psa_key_handle_t handle = 0;

    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t first_part_size = first_part_size_arg;
    size_t output1_length = output1_length_arg;
    size_t output2_length = output2_length_arg;
    unsigned char *output = NULL;
    size_t output_buffer_size = 0;
    size_t function_output_length = 0;
    size_t total_output_length = 0;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_cipher_decrypt_setup( &operation,
                                          handle, alg ) );

    PSA_ASSERT( psa_cipher_set_iv( &operation, iv->x, iv->len ) );

    output_buffer_size = ( (size_t) input->len +
                           PSA_BLOCK_CIPHER_BLOCK_SIZE( key_type ) );
    ASSERT_ALLOC( output, output_buffer_size );

    TEST_ASSERT( first_part_size <= input->len );
    PSA_ASSERT( psa_cipher_update( &operation,
                                   input->x, first_part_size,
                                   output, output_buffer_size,
                                   &function_output_length ) );
    TEST_ASSERT( function_output_length == output1_length );
    total_output_length += function_output_length;
    PSA_ASSERT( psa_cipher_update( &operation,
                                   input->x + first_part_size,
                                   input->len - first_part_size,
                                   output + total_output_length,
                                   output_buffer_size - total_output_length,
                                   &function_output_length ) );
    TEST_ASSERT( function_output_length == output2_length );
    total_output_length += function_output_length;
    PSA_ASSERT( psa_cipher_finish( &operation,
                                   output + total_output_length,
                                   output_buffer_size - total_output_length,
                                   &function_output_length ) );
    total_output_length += function_output_length;
    PSA_ASSERT( psa_cipher_abort( &operation ) );

    ASSERT_COMPARE( expected_output->x, expected_output->len,
                    output, total_output_length );

exit:
    mbedtls_free( output );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_decrypt_multipart_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data11 = {(uint8_t *) params[11], *( (uint32_t *) params[12] )};

    test_cipher_decrypt_multipart( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, *( (int *) params[8] ), *( (int *) params[9] ), *( (int *) params[10] ), &data11 );
}
#line 3521 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_decrypt( int alg_arg, int key_type_arg,
                     data_t *key, data_t *iv,
                     data_t *input, data_t *expected_output,
                     int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_status_t status;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    unsigned char *output = NULL;
    size_t output_buffer_size = 0;
    size_t function_output_length = 0;
    size_t total_output_length = 0;
    psa_cipher_operation_t operation = PSA_CIPHER_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_cipher_decrypt_setup( &operation,
                                          handle, alg ) );

    PSA_ASSERT( psa_cipher_set_iv( &operation, iv->x, iv->len ) );

    output_buffer_size = ( (size_t) input->len +
                           PSA_BLOCK_CIPHER_BLOCK_SIZE( key_type ) );
    ASSERT_ALLOC( output, output_buffer_size );

    PSA_ASSERT( psa_cipher_update( &operation,
                                   input->x, input->len,
                                   output, output_buffer_size,
                                   &function_output_length ) );
    total_output_length += function_output_length;
    status = psa_cipher_finish( &operation,
                                output + total_output_length,
                                output_buffer_size - total_output_length,
                                &function_output_length );
    total_output_length += function_output_length;
    TEST_EQUAL( status, expected_status );

    if( expected_status == PSA_SUCCESS )
    {
        PSA_ASSERT( psa_cipher_abort( &operation ) );
        ASSERT_COMPARE( expected_output->x, expected_output->len,
                        output, total_output_length );
    }

exit:
    mbedtls_free( output );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_decrypt_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_cipher_decrypt( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, &data8, *( (int *) params[10] ) );
}
#line 3582 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_verify_output( int alg_arg, int key_type_arg,
                           data_t *key,
                           data_t *input )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    unsigned char iv[16] = {0};
    size_t iv_size = 16;
    size_t iv_length = 0;
    unsigned char *output1 = NULL;
    size_t output1_size = 0;
    size_t output1_length = 0;
    unsigned char *output2 = NULL;
    size_t output2_size = 0;
    size_t output2_length = 0;
    size_t function_output_length = 0;
    psa_cipher_operation_t operation1 = PSA_CIPHER_OPERATION_INIT;
    psa_cipher_operation_t operation2 = PSA_CIPHER_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_cipher_encrypt_setup( &operation1,
                                          handle, alg ) );
    PSA_ASSERT( psa_cipher_decrypt_setup( &operation2,
                                          handle, alg ) );

    PSA_ASSERT( psa_cipher_generate_iv( &operation1,
                                        iv, iv_size,
                                        &iv_length ) );
    output1_size = ( (size_t) input->len +
                     PSA_BLOCK_CIPHER_BLOCK_SIZE( key_type ) );
    ASSERT_ALLOC( output1, output1_size );

    PSA_ASSERT( psa_cipher_update( &operation1, input->x, input->len,
                                   output1, output1_size,
                                   &output1_length ) );
    PSA_ASSERT( psa_cipher_finish( &operation1,
                                   output1 + output1_length,
                                   output1_size - output1_length,
                                   &function_output_length ) );

    output1_length += function_output_length;

    PSA_ASSERT( psa_cipher_abort( &operation1 ) );

    output2_size = output1_length;
    ASSERT_ALLOC( output2, output2_size );

    PSA_ASSERT( psa_cipher_set_iv( &operation2,
                                   iv, iv_length ) );
    PSA_ASSERT( psa_cipher_update( &operation2, output1, output1_length,
                                   output2, output2_size,
                                   &output2_length ) );
    function_output_length = 0;
    PSA_ASSERT( psa_cipher_finish( &operation2,
                                   output2 + output2_length,
                                   output2_size - output2_length,
                                   &function_output_length ) );

    output2_length += function_output_length;

    PSA_ASSERT( psa_cipher_abort( &operation2 ) );

    ASSERT_COMPARE( input->x, input->len, output2, output2_length );

exit:
    mbedtls_free( output1 );
    mbedtls_free( output2 );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_verify_output_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_cipher_verify_output( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4 );
}
#line 3664 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_cipher_verify_output_multipart( int alg_arg,
                                     int key_type_arg,
                                     data_t *key,
                                     data_t *input,
                                     int first_part_size_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t first_part_size = first_part_size_arg;
    unsigned char iv[16] = {0};
    size_t iv_size = 16;
    size_t iv_length = 0;
    unsigned char *output1 = NULL;
    size_t output1_buffer_size = 0;
    size_t output1_length = 0;
    unsigned char *output2 = NULL;
    size_t output2_buffer_size = 0;
    size_t output2_length = 0;
    size_t function_output_length;
    psa_cipher_operation_t operation1 = PSA_CIPHER_OPERATION_INIT;
    psa_cipher_operation_t operation2 = PSA_CIPHER_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key->x, key->len, &handle ) );

    PSA_ASSERT( psa_cipher_encrypt_setup( &operation1,
                                          handle, alg ) );
    PSA_ASSERT( psa_cipher_decrypt_setup( &operation2,
                                          handle, alg ) );

    PSA_ASSERT( psa_cipher_generate_iv( &operation1,
                                        iv, iv_size,
                                        &iv_length ) );
    output1_buffer_size = ( (size_t) input->len +
                            PSA_BLOCK_CIPHER_BLOCK_SIZE( key_type ) );
    ASSERT_ALLOC( output1, output1_buffer_size );

    TEST_ASSERT( first_part_size <= input->len );

    PSA_ASSERT( psa_cipher_update( &operation1, input->x, first_part_size,
                                   output1, output1_buffer_size,
                                   &function_output_length ) );
    output1_length += function_output_length;

    PSA_ASSERT( psa_cipher_update( &operation1,
                                   input->x + first_part_size,
                                   input->len - first_part_size,
                                   output1, output1_buffer_size,
                                   &function_output_length ) );
    output1_length += function_output_length;

    PSA_ASSERT( psa_cipher_finish( &operation1,
                                   output1 + output1_length,
                                   output1_buffer_size - output1_length,
                                   &function_output_length ) );
    output1_length += function_output_length;

    PSA_ASSERT( psa_cipher_abort( &operation1 ) );

    output2_buffer_size = output1_length;
    ASSERT_ALLOC( output2, output2_buffer_size );

    PSA_ASSERT( psa_cipher_set_iv( &operation2,
                                   iv, iv_length ) );

    PSA_ASSERT( psa_cipher_update( &operation2, output1, first_part_size,
                                   output2, output2_buffer_size,
                                   &function_output_length ) );
    output2_length += function_output_length;

    PSA_ASSERT( psa_cipher_update( &operation2,
                                   output1 + first_part_size,
                                   output1_length - first_part_size,
                                   output2, output2_buffer_size,
                                   &function_output_length ) );
    output2_length += function_output_length;

    PSA_ASSERT( psa_cipher_finish( &operation2,
                                   output2 + output2_length,
                                   output2_buffer_size - output2_length,
                                   &function_output_length ) );
    output2_length += function_output_length;

    PSA_ASSERT( psa_cipher_abort( &operation2 ) );

    ASSERT_COMPARE( input->x, input->len, output2, output2_length );

exit:
    mbedtls_free( output1 );
    mbedtls_free( output2 );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_cipher_verify_output_multipart_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_cipher_verify_output_multipart( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, *( (int *) params[6] ) );
}
#line 3767 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_aead_encrypt_decrypt( int key_type_arg, data_t *key_data,
                           int alg_arg,
                           data_t *nonce,
                           data_t *additional_data,
                           data_t *input_data,
                           int expected_result_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    unsigned char *output_data = NULL;
    size_t output_size = 0;
    size_t output_length = 0;
    unsigned char *output_data2 = NULL;
    size_t output_length2 = 0;
    size_t tag_length = PSA_AEAD_TAG_LENGTH( alg );
    psa_status_t expected_result = expected_result_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    output_size = input_data->len + tag_length;
    /* For all currently defined algorithms, PSA_AEAD_ENCRYPT_OUTPUT_SIZE
     * should be exact. */
    if( expected_result != PSA_ERROR_INVALID_ARGUMENT )
        TEST_EQUAL( output_size,
                    PSA_AEAD_ENCRYPT_OUTPUT_SIZE( alg, input_data->len ) );
    ASSERT_ALLOC( output_data, output_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    TEST_EQUAL( psa_aead_encrypt( handle, alg,
                                  nonce->x, nonce->len,
                                  additional_data->x,
                                  additional_data->len,
                                  input_data->x, input_data->len,
                                  output_data, output_size,
                                  &output_length ),
                expected_result );

    if( PSA_SUCCESS == expected_result )
    {
        ASSERT_ALLOC( output_data2, output_length );

        /* For all currently defined algorithms, PSA_AEAD_DECRYPT_OUTPUT_SIZE
         * should be exact. */
        TEST_EQUAL( input_data->len,
                    PSA_AEAD_DECRYPT_OUTPUT_SIZE( alg, output_length ) );

        TEST_EQUAL( psa_aead_decrypt( handle, alg,
                                      nonce->x, nonce->len,
                                      additional_data->x,
                                      additional_data->len,
                                      output_data, output_length,
                                      output_data2, output_length,
                                      &output_length2 ),
                    expected_result );

        ASSERT_COMPARE( input_data->x, input_data->len,
                        output_data2, output_length2 );
    }

exit:
    psa_destroy_key( handle );
    mbedtls_free( output_data );
    mbedtls_free( output_data2 );
    PSA_DONE( );
}

void test_aead_encrypt_decrypt_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_aead_encrypt_decrypt( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, &data8, *( (int *) params[10] ) );
}
#line 3843 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_aead_encrypt( int key_type_arg, data_t *key_data,
                   int alg_arg,
                   data_t *nonce,
                   data_t *additional_data,
                   data_t *input_data,
                   data_t *expected_result )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    unsigned char *output_data = NULL;
    size_t output_size = 0;
    size_t output_length = 0;
    size_t tag_length = PSA_AEAD_TAG_LENGTH( alg );
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    output_size = input_data->len + tag_length;
    /* For all currently defined algorithms, PSA_AEAD_ENCRYPT_OUTPUT_SIZE
     * should be exact. */
    TEST_EQUAL( output_size,
                PSA_AEAD_ENCRYPT_OUTPUT_SIZE( alg, input_data->len ) );
    ASSERT_ALLOC( output_data, output_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT  );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_aead_encrypt( handle, alg,
                                  nonce->x, nonce->len,
                                  additional_data->x, additional_data->len,
                                  input_data->x, input_data->len,
                                  output_data, output_size,
                                  &output_length ) );

    ASSERT_COMPARE( expected_result->x, expected_result->len,
                    output_data, output_length );

exit:
    psa_destroy_key( handle );
    mbedtls_free( output_data );
    PSA_DONE( );
}

void test_aead_encrypt_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};
    data_t data10 = {(uint8_t *) params[10], *( (uint32_t *) params[11] )};

    test_aead_encrypt( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, &data8, &data10 );
}
#line 3893 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_aead_decrypt( int key_type_arg, data_t *key_data,
                   int alg_arg,
                   data_t *nonce,
                   data_t *additional_data,
                   data_t *input_data,
                   data_t *expected_data,
                   int expected_result_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    unsigned char *output_data = NULL;
    size_t output_size = 0;
    size_t output_length = 0;
    size_t tag_length = PSA_AEAD_TAG_LENGTH( alg );
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t expected_result = expected_result_arg;

    output_size = input_data->len - tag_length;
    /* For all currently defined algorithms, PSA_AEAD_DECRYPT_OUTPUT_SIZE
     * should be exact. */
    if( expected_result != PSA_ERROR_INVALID_ARGUMENT )
        TEST_EQUAL( output_size,
                    PSA_AEAD_DECRYPT_OUTPUT_SIZE( alg, input_data->len ) );
    ASSERT_ALLOC( output_data, output_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DECRYPT  );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    TEST_EQUAL( psa_aead_decrypt( handle, alg,
                                  nonce->x, nonce->len,
                                  additional_data->x,
                                  additional_data->len,
                                  input_data->x, input_data->len,
                                  output_data, output_size,
                                  &output_length ),
                expected_result );

    if( expected_result == PSA_SUCCESS )
        ASSERT_COMPARE( expected_data->x, expected_data->len,
                        output_data, output_length );

exit:
    psa_destroy_key( handle );
    mbedtls_free( output_data );
    PSA_DONE( );
}

void test_aead_decrypt_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};
    data_t data10 = {(uint8_t *) params[10], *( (uint32_t *) params[11] )};

    test_aead_decrypt( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, &data8, &data10, *( (int *) params[12] ) );
}
#line 3949 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_signature_size( int type_arg,
                     int bits,
                     int alg_arg,
                     int expected_size_arg )
{
    psa_key_type_t type = type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t actual_size = PSA_SIGN_OUTPUT_SIZE( type, bits, alg );

    TEST_EQUAL( actual_size, (size_t) expected_size_arg );
#if defined(MBEDTLS_TEST_DEPRECATED)
    TEST_EQUAL( actual_size,
                PSA_ASYMMETRIC_SIGN_OUTPUT_SIZE( type, bits, alg ) );
#endif /* MBEDTLS_TEST_DEPRECATED */

exit:
    ;
}

void test_signature_size_wrapper( void ** params )
{

    test_signature_size( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ) );
}
#line 3970 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_sign_deterministic( int key_type_arg, data_t *key_data,
                         int alg_arg, data_t *input_data,
                         data_t *output_data )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t key_bits;
    unsigned char *signature = NULL;
    size_t signature_size;
    size_t signature_length = 0xdeadbeef;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    key_bits = psa_get_key_bits( &attributes );

    /* Allocate a buffer which has the size advertized by the
     * library. */
    signature_size = PSA_SIGN_OUTPUT_SIZE( key_type,
                                                      key_bits, alg );
    TEST_ASSERT( signature_size != 0 );
    TEST_ASSERT( signature_size <= PSA_SIGNATURE_MAX_SIZE );
    ASSERT_ALLOC( signature, signature_size );

    /* Perform the signature. */
    PSA_ASSERT( psa_sign_hash( handle, alg,
                               input_data->x, input_data->len,
                               signature, signature_size,
                               &signature_length ) );
    /* Verify that the signature is what is expected. */
    ASSERT_COMPARE( output_data->x, output_data->len,
                    signature, signature_length );

#if defined(MBEDTLS_TEST_DEPRECATED)
    memset( signature, 0, signature_size );
    signature_length = INVALID_EXPORT_LENGTH;
    PSA_ASSERT( psa_asymmetric_sign( handle, alg,
                                     input_data->x, input_data->len,
                                     signature, signature_size,
                                     &signature_length ) );
    ASSERT_COMPARE( output_data->x, output_data->len,
                    signature, signature_length );
#endif /* MBEDTLS_TEST_DEPRECATED */

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( signature );
    PSA_DONE( );
}

void test_sign_deterministic_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_sign_deterministic( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6 );
}
#line 4031 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_sign_fail( int key_type_arg, data_t *key_data,
                int alg_arg, data_t *input_data,
                int signature_size_arg, int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t signature_size = signature_size_arg;
    psa_status_t actual_status;
    psa_status_t expected_status = expected_status_arg;
    unsigned char *signature = NULL;
    size_t signature_length = 0xdeadbeef;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    ASSERT_ALLOC( signature, signature_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    actual_status = psa_sign_hash( handle, alg,
                                   input_data->x, input_data->len,
                                   signature, signature_size,
                                   &signature_length );
    TEST_EQUAL( actual_status, expected_status );
    /* The value of *signature_length is unspecified on error, but
     * whatever it is, it should be less than signature_size, so that
     * if the caller tries to read *signature_length bytes without
     * checking the error code then they don't overflow a buffer. */
    TEST_ASSERT( signature_length <= signature_size );

#if defined(MBEDTLS_TEST_DEPRECATED)
    signature_length = INVALID_EXPORT_LENGTH;
    TEST_EQUAL( psa_asymmetric_sign( handle, alg,
                                     input_data->x, input_data->len,
                                     signature, signature_size,
                                     &signature_length ),
                expected_status );
    TEST_ASSERT( signature_length <= signature_size );
#endif /* MBEDTLS_TEST_DEPRECATED */

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( signature );
    PSA_DONE( );
}

void test_sign_fail_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_sign_fail( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, *( (int *) params[6] ), *( (int *) params[7] ) );
}
#line 4086 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_sign_verify( int key_type_arg, data_t *key_data,
                  int alg_arg, data_t *input_data )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t key_bits;
    unsigned char *signature = NULL;
    size_t signature_size;
    size_t signature_length = 0xdeadbeef;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    key_bits = psa_get_key_bits( &attributes );

    /* Allocate a buffer which has the size advertized by the
     * library. */
    signature_size = PSA_SIGN_OUTPUT_SIZE( key_type,
                                                      key_bits, alg );
    TEST_ASSERT( signature_size != 0 );
    TEST_ASSERT( signature_size <= PSA_SIGNATURE_MAX_SIZE );
    ASSERT_ALLOC( signature, signature_size );

    /* Perform the signature. */
    PSA_ASSERT( psa_sign_hash( handle, alg,
                               input_data->x, input_data->len,
                               signature, signature_size,
                               &signature_length ) );
    /* Check that the signature length looks sensible. */
    TEST_ASSERT( signature_length <= signature_size );
    TEST_ASSERT( signature_length > 0 );

    /* Use the library to verify that the signature is correct. */
    PSA_ASSERT( psa_verify_hash( handle, alg,
                                 input_data->x, input_data->len,
                                 signature, signature_length ) );

    if( input_data->len != 0 )
    {
        /* Flip a bit in the input and verify that the signature is now
         * detected as invalid. Flip a bit at the beginning, not at the end,
         * because ECDSA may ignore the last few bits of the input. */
        input_data->x[0] ^= 1;
        TEST_EQUAL( psa_verify_hash( handle, alg,
                                     input_data->x, input_data->len,
                                     signature, signature_length ),
                    PSA_ERROR_INVALID_SIGNATURE );
    }

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( signature );
    PSA_DONE( );
}

void test_sign_verify_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_sign_verify( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4 );
}
#line 4152 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_verify( int key_type_arg, data_t *key_data,
                        int alg_arg, data_t *hash_data,
                        data_t *signature_data )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    TEST_ASSERT( signature_data->len <= PSA_SIGNATURE_MAX_SIZE );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_verify_hash( handle, alg,
                                 hash_data->x, hash_data->len,
                                 signature_data->x, signature_data->len ) );

#if defined(MBEDTLS_TEST_DEPRECATED)
    PSA_ASSERT( psa_asymmetric_verify( handle, alg,
                                       hash_data->x, hash_data->len,
                                       signature_data->x,
                                       signature_data->len ) );

#endif /* MBEDTLS_TEST_DEPRECATED */

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_asymmetric_verify_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_asymmetric_verify( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6 );
}
#line 4192 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_verify_fail( int key_type_arg, data_t *key_data,
                             int alg_arg, data_t *hash_data,
                             data_t *signature_data,
                             int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t actual_status;
    psa_status_t expected_status = expected_status_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    actual_status = psa_verify_hash( handle, alg,
                                     hash_data->x, hash_data->len,
                                     signature_data->x, signature_data->len );
    TEST_EQUAL( actual_status, expected_status );

#if defined(MBEDTLS_TEST_DEPRECATED)
    TEST_EQUAL( psa_asymmetric_verify( handle, alg,
                                       hash_data->x, hash_data->len,
                                       signature_data->x, signature_data->len ),
                expected_status );
#endif /* MBEDTLS_TEST_DEPRECATED */

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_asymmetric_verify_fail_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_asymmetric_verify_fail( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, *( (int *) params[8] ) );
}
#line 4233 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_encrypt( int key_type_arg,
                         data_t *key_data,
                         int alg_arg,
                         data_t *input_data,
                         data_t *label,
                         int expected_output_length_arg,
                         int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t expected_output_length = expected_output_length_arg;
    size_t key_bits;
    unsigned char *output = NULL;
    size_t output_size;
    size_t output_length = ~0;
    psa_status_t actual_status;
    psa_status_t expected_status = expected_status_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    /* Import the key */
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );
    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    /* Determine the maximum output length */
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    key_bits = psa_get_key_bits( &attributes );
    output_size = PSA_ASYMMETRIC_ENCRYPT_OUTPUT_SIZE( key_type, key_bits, alg );
    ASSERT_ALLOC( output, output_size );

    /* Encrypt the input */
    actual_status = psa_asymmetric_encrypt( handle, alg,
                                            input_data->x, input_data->len,
                                            label->x, label->len,
                                            output, output_size,
                                            &output_length );
    TEST_EQUAL( actual_status, expected_status );
    TEST_EQUAL( output_length, expected_output_length );

    /* If the label is empty, the test framework puts a non-null pointer
     * in label->x. Test that a null pointer works as well. */
    if( label->len == 0 )
    {
        output_length = ~0;
        if( output_size != 0 )
            memset( output, 0, output_size );
        actual_status = psa_asymmetric_encrypt( handle, alg,
                                                input_data->x, input_data->len,
                                                NULL, label->len,
                                                output, output_size,
                                                &output_length );
        TEST_EQUAL( actual_status, expected_status );
        TEST_EQUAL( output_length, expected_output_length );
    }

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( output );
    PSA_DONE( );
}

void test_asymmetric_encrypt_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_asymmetric_encrypt( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, *( (int *) params[8] ), *( (int *) params[9] ) );
}
#line 4302 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_encrypt_decrypt( int key_type_arg,
                                 data_t *key_data,
                                 int alg_arg,
                                 data_t *input_data,
                                 data_t *label )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t key_bits;
    unsigned char *output = NULL;
    size_t output_size;
    size_t output_length = ~0;
    unsigned char *output2 = NULL;
    size_t output2_size;
    size_t output2_length = ~0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    /* Determine the maximum ciphertext length */
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    key_bits = psa_get_key_bits( &attributes );
    output_size = PSA_ASYMMETRIC_ENCRYPT_OUTPUT_SIZE( key_type, key_bits, alg );
    ASSERT_ALLOC( output, output_size );
    output2_size = input_data->len;
    ASSERT_ALLOC( output2, output2_size );

    /* We test encryption by checking that encrypt-then-decrypt gives back
     * the original plaintext because of the non-optional random
     * part of encryption process which prevents using fixed vectors. */
    PSA_ASSERT( psa_asymmetric_encrypt( handle, alg,
                                        input_data->x, input_data->len,
                                        label->x, label->len,
                                        output, output_size,
                                        &output_length ) );
    /* We don't know what ciphertext length to expect, but check that
     * it looks sensible. */
    TEST_ASSERT( output_length <= output_size );

    PSA_ASSERT( psa_asymmetric_decrypt( handle, alg,
                                        output, output_length,
                                        label->x, label->len,
                                        output2, output2_size,
                                        &output2_length ) );
    ASSERT_COMPARE( input_data->x, input_data->len,
                    output2, output2_length );

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( output );
    mbedtls_free( output2 );
    PSA_DONE( );
}

void test_asymmetric_encrypt_decrypt_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_asymmetric_encrypt_decrypt( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6 );
}
#line 4367 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_decrypt( int key_type_arg,
                         data_t *key_data,
                         int alg_arg,
                         data_t *input_data,
                         data_t *label,
                         data_t *expected_data )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    unsigned char *output = NULL;
    size_t output_size = 0;
    size_t output_length = ~0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    output_size = expected_data->len;
    ASSERT_ALLOC( output, output_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    PSA_ASSERT( psa_asymmetric_decrypt( handle, alg,
                                        input_data->x, input_data->len,
                                        label->x, label->len,
                                        output,
                                        output_size,
                                        &output_length ) );
    ASSERT_COMPARE( expected_data->x, expected_data->len,
                    output, output_length );

    /* If the label is empty, the test framework puts a non-null pointer
     * in label->x. Test that a null pointer works as well. */
    if( label->len == 0 )
    {
        output_length = ~0;
        if( output_size != 0 )
            memset( output, 0, output_size );
        PSA_ASSERT( psa_asymmetric_decrypt( handle, alg,
                                            input_data->x, input_data->len,
                                            NULL, label->len,
                                            output,
                                            output_size,
                                            &output_length ) );
        ASSERT_COMPARE( expected_data->x, expected_data->len,
                        output, output_length );
    }

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( output );
    PSA_DONE( );
}

void test_asymmetric_decrypt_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_asymmetric_decrypt( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, &data8 );
}
#line 4429 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_asymmetric_decrypt_fail( int key_type_arg,
                              data_t *key_data,
                              int alg_arg,
                              data_t *input_data,
                              data_t *label,
                              int output_size_arg,
                              int expected_status_arg  )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t key_type = key_type_arg;
    psa_algorithm_t alg = alg_arg;
    unsigned char *output = NULL;
    size_t output_size = output_size_arg;
    size_t output_length = ~0;
    psa_status_t actual_status;
    psa_status_t expected_status = expected_status_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    ASSERT_ALLOC( output, output_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DECRYPT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    actual_status = psa_asymmetric_decrypt( handle, alg,
                                            input_data->x, input_data->len,
                                            label->x, label->len,
                                            output, output_size,
                                            &output_length );
    TEST_EQUAL( actual_status, expected_status );
    TEST_ASSERT( output_length <= output_size );

    /* If the label is empty, the test framework puts a non-null pointer
     * in label->x. Test that a null pointer works as well. */
    if( label->len == 0 )
    {
        output_length = ~0;
        if( output_size != 0 )
            memset( output, 0, output_size );
        actual_status = psa_asymmetric_decrypt( handle, alg,
                                                input_data->x, input_data->len,
                                                NULL, label->len,
                                                output, output_size,
                                                &output_length );
        TEST_EQUAL( actual_status, expected_status );
        TEST_ASSERT( output_length <= output_size );
    }

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    mbedtls_free( output );
    PSA_DONE( );
}

void test_asymmetric_decrypt_fail_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_asymmetric_decrypt_fail( *( (int *) params[0] ), &data1, *( (int *) params[3] ), &data4, &data6, *( (int *) params[8] ), *( (int *) params[9] ) );
}
#line 4491 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_key_derivation_init( )
{
    /* Test each valid way of initializing the object, except for `= {0}`, as
     * Clang 5 complains when `-Wmissing-field-initializers` is used, even
     * though it's OK by the C standard. We could test for this, but we'd need
     * to supress the Clang warning for the test. */
    size_t capacity;
    psa_key_derivation_operation_t func = psa_key_derivation_operation_init( );
    psa_key_derivation_operation_t init = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_derivation_operation_t zero;

    memset( &zero, 0, sizeof( zero ) );

    /* A default operation should not be able to report its capacity. */
    TEST_EQUAL( psa_key_derivation_get_capacity( &func, &capacity ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_key_derivation_get_capacity( &init, &capacity ),
                PSA_ERROR_BAD_STATE );
    TEST_EQUAL( psa_key_derivation_get_capacity( &zero, &capacity ),
                PSA_ERROR_BAD_STATE );

    /* A default operation should be abortable without error. */
    PSA_ASSERT( psa_key_derivation_abort(&func) );
    PSA_ASSERT( psa_key_derivation_abort(&init) );
    PSA_ASSERT( psa_key_derivation_abort(&zero) );
exit:
    ;
}

void test_key_derivation_init_wrapper( void ** params )
{
    (void)params;

    test_key_derivation_init(  );
}
#line 4520 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_setup( int alg_arg, int expected_status_arg )
{
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    TEST_EQUAL( psa_key_derivation_setup( &operation, alg ),
                expected_status );

exit:
    psa_key_derivation_abort( &operation );
    PSA_DONE( );
}

void test_derive_setup_wrapper( void ** params )
{

    test_derive_setup( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#line 4538 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_set_capacity( int alg_arg, int capacity_arg,
                          int expected_status_arg )
{
    psa_algorithm_t alg = alg_arg;
    size_t capacity = capacity_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    PSA_ASSERT( psa_key_derivation_setup( &operation, alg ) );

    TEST_EQUAL( psa_key_derivation_set_capacity( &operation, capacity ),
                expected_status );

exit:
    psa_key_derivation_abort( &operation );
    PSA_DONE( );
}

void test_derive_set_capacity_wrapper( void ** params )
{

    test_derive_set_capacity( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 4560 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_input( int alg_arg,
                   int step_arg1, int key_type_arg1, data_t *input1,
                   int expected_status_arg1,
                   int step_arg2, int key_type_arg2, data_t *input2,
                   int expected_status_arg2,
                   int step_arg3, int key_type_arg3, data_t *input3,
                   int expected_status_arg3,
                   int output_key_type_arg, int expected_output_status_arg )
{
    psa_algorithm_t alg = alg_arg;
    psa_key_derivation_step_t steps[] = {step_arg1, step_arg2, step_arg3};
    psa_key_type_t key_types[] = {key_type_arg1, key_type_arg2, key_type_arg3};
    psa_status_t expected_statuses[] = {expected_status_arg1,
                                        expected_status_arg2,
                                        expected_status_arg3};
    data_t *inputs[] = {input1, input2, input3};
    psa_key_handle_t handles[] = {0, 0, 0};
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    size_t i;
    psa_key_type_t output_key_type = output_key_type_arg;
    psa_key_handle_t output_handle = 0;
    psa_status_t expected_output_status = expected_output_status_arg;
    psa_status_t actual_output_status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );

    PSA_ASSERT( psa_key_derivation_setup( &operation, alg ) );

    for( i = 0; i < ARRAY_LENGTH( steps ); i++ )
    {
        if( key_types[i] != PSA_KEY_TYPE_NONE )
        {
            psa_set_key_type( &attributes, key_types[i] );
            PSA_ASSERT( psa_import_key( &attributes,
                                        inputs[i]->x, inputs[i]->len,
                                        &handles[i] ) );
            TEST_EQUAL( psa_key_derivation_input_key( &operation, steps[i],
                                                      handles[i] ),
                        expected_statuses[i] );
        }
        else
        {
            TEST_EQUAL( psa_key_derivation_input_bytes(
                            &operation, steps[i],
                            inputs[i]->x, inputs[i]->len ),
                        expected_statuses[i] );
        }
    }

    if( output_key_type != PSA_KEY_TYPE_NONE )
    {
        psa_reset_key_attributes( &attributes );
        psa_set_key_type( &attributes, PSA_KEY_TYPE_RAW_DATA );
        psa_set_key_bits( &attributes, 8 );
        actual_output_status =
            psa_key_derivation_output_key( &attributes, &operation,
                                           &output_handle );
    }
    else
    {
        uint8_t buffer[1];
        actual_output_status =
            psa_key_derivation_output_bytes( &operation,
                                             buffer, sizeof( buffer ) );
    }
    TEST_EQUAL( actual_output_status, expected_output_status );

exit:
    psa_key_derivation_abort( &operation );
    for( i = 0; i < ARRAY_LENGTH( handles ); i++ )
        psa_destroy_key( handles[i] );
    psa_destroy_key( output_handle );
    PSA_DONE( );
}

void test_derive_input_wrapper( void ** params )
{
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};
    data_t data13 = {(uint8_t *) params[13], *( (uint32_t *) params[14] )};

    test_derive_input( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), &data3, *( (int *) params[5] ), *( (int *) params[6] ), *( (int *) params[7] ), &data8, *( (int *) params[10] ), *( (int *) params[11] ), *( (int *) params[12] ), &data13, *( (int *) params[15] ), *( (int *) params[16] ), *( (int *) params[17] ) );
}
#line 4641 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_test_derive_invalid_key_derivation_state( int alg_arg )
{
    psa_algorithm_t alg = alg_arg;
    psa_key_handle_t handle = 0;
    size_t key_type = PSA_KEY_TYPE_DERIVE;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    unsigned char input1[] = "Input 1";
    size_t input1_length = sizeof( input1 );
    unsigned char input2[] = "Input 2";
    size_t input2_length = sizeof( input2 );
    uint8_t buffer[42];
    size_t capacity = sizeof( buffer );
    const uint8_t key_data[22] = { 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
                                   0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
                                   0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b};
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, key_type );

    PSA_ASSERT( psa_import_key( &attributes,
                                key_data, sizeof( key_data ),
                                &handle ) );

    /* valid key derivation */
    if( !setup_key_derivation_wrap( &operation, handle, alg,
                                    input1, input1_length,
                                    input2, input2_length,
                                    capacity ) )
        goto exit;

    /* state of operation shouldn't allow additional generation */
    TEST_EQUAL(  psa_key_derivation_setup( &operation, alg ),
                 PSA_ERROR_BAD_STATE );

    PSA_ASSERT( psa_key_derivation_output_bytes( &operation, buffer, capacity ) );

    TEST_EQUAL( psa_key_derivation_output_bytes( &operation, buffer, capacity ),
                PSA_ERROR_INSUFFICIENT_DATA );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_test_derive_invalid_key_derivation_state_wrapper( void ** params )
{

    test_test_derive_invalid_key_derivation_state( *( (int *) params[0] ) );
}
#line 4692 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_test_derive_invalid_key_derivation_tests( )
{
    uint8_t output_buffer[16];
    size_t buffer_size = 16;
    size_t capacity = 0;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;

    TEST_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                  output_buffer, buffer_size )
                 == PSA_ERROR_BAD_STATE );

    TEST_ASSERT( psa_key_derivation_get_capacity( &operation, &capacity )
                 == PSA_ERROR_BAD_STATE );

    PSA_ASSERT( psa_key_derivation_abort( &operation ) );

    TEST_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                  output_buffer, buffer_size )
                 == PSA_ERROR_BAD_STATE );

    TEST_ASSERT( psa_key_derivation_get_capacity( &operation, &capacity )
                 == PSA_ERROR_BAD_STATE );

exit:
    psa_key_derivation_abort( &operation );
}

void test_test_derive_invalid_key_derivation_tests_wrapper( void ** params )
{
    (void)params;

    test_test_derive_invalid_key_derivation_tests(  );
}
#line 4721 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_output( int alg_arg,
                    int step1_arg, data_t *input1,
                    int step2_arg, data_t *input2,
                    int step3_arg, data_t *input3,
                    int requested_capacity_arg,
                    data_t *expected_output1,
                    data_t *expected_output2 )
{
    psa_algorithm_t alg = alg_arg;
    psa_key_derivation_step_t steps[] = {step1_arg, step2_arg, step3_arg};
    data_t *inputs[] = {input1, input2, input3};
    psa_key_handle_t handles[] = {0, 0, 0};
    size_t requested_capacity = requested_capacity_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    uint8_t *expected_outputs[2] =
        {expected_output1->x, expected_output2->x};
    size_t output_sizes[2] =
        {expected_output1->len, expected_output2->len};
    size_t output_buffer_size = 0;
    uint8_t *output_buffer = NULL;
    size_t expected_capacity;
    size_t current_capacity;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t status;
    size_t i;

    for( i = 0; i < ARRAY_LENGTH( expected_outputs ); i++ )
    {
        if( output_sizes[i] > output_buffer_size )
            output_buffer_size = output_sizes[i];
        if( output_sizes[i] == 0 )
            expected_outputs[i] = NULL;
    }
    ASSERT_ALLOC( output_buffer, output_buffer_size );
    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_DERIVE );

    /* Extraction phase. */
    PSA_ASSERT( psa_key_derivation_setup( &operation, alg ) );
    PSA_ASSERT( psa_key_derivation_set_capacity( &operation,
                                                 requested_capacity ) );
    for( i = 0; i < ARRAY_LENGTH( steps ); i++ )
    {
        switch( steps[i] )
        {
            case 0:
                break;
            case PSA_KEY_DERIVATION_INPUT_SECRET:
                PSA_ASSERT( psa_import_key( &attributes,
                                            inputs[i]->x, inputs[i]->len,
                                            &handles[i] ) );
                PSA_ASSERT( psa_key_derivation_input_key(
                                &operation, steps[i],
                                handles[i] ) );
                break;
            default:
                PSA_ASSERT( psa_key_derivation_input_bytes(
                                &operation, steps[i],
                                inputs[i]->x, inputs[i]->len ) );
                break;
        }
    }

    PSA_ASSERT( psa_key_derivation_get_capacity( &operation,
                                                 &current_capacity ) );
    TEST_EQUAL( current_capacity, requested_capacity );
    expected_capacity = requested_capacity;

    /* Expansion phase. */
    for( i = 0; i < ARRAY_LENGTH( expected_outputs ); i++ )
    {
        /* Read some bytes. */
        status = psa_key_derivation_output_bytes( &operation,
                                                  output_buffer, output_sizes[i] );
        if( expected_capacity == 0 && output_sizes[i] == 0 )
        {
            /* Reading 0 bytes when 0 bytes are available can go either way. */
            TEST_ASSERT( status == PSA_SUCCESS ||
                         status == PSA_ERROR_INSUFFICIENT_DATA );
            continue;
        }
        else if( expected_capacity == 0 ||
                 output_sizes[i] > expected_capacity )
        {
            /* Capacity exceeded. */
            TEST_EQUAL( status, PSA_ERROR_INSUFFICIENT_DATA );
            expected_capacity = 0;
            continue;
        }
        /* Success. Check the read data. */
        PSA_ASSERT( status );
        if( output_sizes[i] != 0 )
            ASSERT_COMPARE( output_buffer, output_sizes[i],
                            expected_outputs[i], output_sizes[i] );
        /* Check the operation status. */
        expected_capacity -= output_sizes[i];
        PSA_ASSERT( psa_key_derivation_get_capacity( &operation,
                                                     &current_capacity ) );
        TEST_EQUAL( expected_capacity, current_capacity );
    }
    PSA_ASSERT( psa_key_derivation_abort( &operation ) );

exit:
    mbedtls_free( output_buffer );
    psa_key_derivation_abort( &operation );
    for( i = 0; i < ARRAY_LENGTH( handles ); i++ )
        psa_destroy_key( handles[i] );
    PSA_DONE( );
}

void test_derive_output_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};
    data_t data11 = {(uint8_t *) params[11], *( (uint32_t *) params[12] )};
    data_t data13 = {(uint8_t *) params[13], *( (uint32_t *) params[14] )};

    test_derive_output( *( (int *) params[0] ), *( (int *) params[1] ), &data2, *( (int *) params[4] ), &data5, *( (int *) params[7] ), &data8, *( (int *) params[10] ), &data11, &data13 );
}
#line 4836 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_full( int alg_arg,
                  data_t *key_data,
                  data_t *input1,
                  data_t *input2,
                  int requested_capacity_arg )
{
    psa_key_handle_t handle = 0;
    psa_algorithm_t alg = alg_arg;
    size_t requested_capacity = requested_capacity_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    unsigned char output_buffer[16];
    size_t expected_capacity = requested_capacity;
    size_t current_capacity;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_DERIVE );

    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &handle ) );

    if( !setup_key_derivation_wrap( &operation, handle, alg,
                                    input1->x, input1->len,
                                    input2->x, input2->len,
                                    requested_capacity ) )
        goto exit;

    PSA_ASSERT( psa_key_derivation_get_capacity( &operation,
                                                 &current_capacity ) );
    TEST_EQUAL( current_capacity, expected_capacity );

    /* Expansion phase. */
    while( current_capacity > 0 )
    {
        size_t read_size = sizeof( output_buffer );
        if( read_size > current_capacity )
            read_size = current_capacity;
        PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                     output_buffer,
                                                     read_size ) );
        expected_capacity -= read_size;
        PSA_ASSERT( psa_key_derivation_get_capacity( &operation,
                                                     &current_capacity ) );
        TEST_EQUAL( current_capacity, expected_capacity );
    }

    /* Check that the operation refuses to go over capacity. */
    TEST_EQUAL( psa_key_derivation_output_bytes( &operation, output_buffer, 1 ),
                PSA_ERROR_INSUFFICIENT_DATA );

    PSA_ASSERT( psa_key_derivation_abort( &operation ) );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_derive_full_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};

    test_derive_full( *( (int *) params[0] ), &data1, &data3, &data5, *( (int *) params[7] ) );
}
#line 4899 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_key_exercise( int alg_arg,
                          data_t *key_data,
                          data_t *input1,
                          data_t *input2,
                          int derived_type_arg,
                          int derived_bits_arg,
                          int derived_usage_arg,
                          int derived_alg_arg )
{
    psa_key_handle_t base_handle = 0;
    psa_key_handle_t derived_handle = 0;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t derived_type = derived_type_arg;
    size_t derived_bits = derived_bits_arg;
    psa_key_usage_t derived_usage = derived_usage_arg;
    psa_algorithm_t derived_alg = derived_alg_arg;
    size_t capacity = PSA_BITS_TO_BYTES( derived_bits );
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_DERIVE );
    PSA_ASSERT( psa_import_key( &attributes, key_data->x, key_data->len,
                                &base_handle ) );

    /* Derive a key. */
    if ( setup_key_derivation_wrap( &operation, base_handle, alg,
                                    input1->x, input1->len,
                                    input2->x, input2->len, capacity ) )
        goto exit;

    psa_set_key_usage_flags( &attributes, derived_usage );
    psa_set_key_algorithm( &attributes, derived_alg );
    psa_set_key_type( &attributes, derived_type );
    psa_set_key_bits( &attributes, derived_bits );
    PSA_ASSERT( psa_key_derivation_output_key( &attributes, &operation,
                                               &derived_handle ) );

    /* Test the key information */
    PSA_ASSERT( psa_get_key_attributes( derived_handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_type( &got_attributes ), derived_type );
    TEST_EQUAL( psa_get_key_bits( &got_attributes ), derived_bits );

    /* Exercise the derived key. */
    if( ! exercise_key( derived_handle, derived_usage, derived_alg ) )
        goto exit;

exit:
    psa_key_derivation_abort( &operation );
    psa_reset_key_attributes( &got_attributes );
    psa_destroy_key( base_handle );
    psa_destroy_key( derived_handle );
    PSA_DONE( );
}

void test_derive_key_exercise_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};

    test_derive_key_exercise( *( (int *) params[0] ), &data1, &data3, &data5, *( (int *) params[7] ), *( (int *) params[8] ), *( (int *) params[9] ), *( (int *) params[10] ) );
}
#line 4960 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_key_export( int alg_arg,
                        data_t *key_data,
                        data_t *input1,
                        data_t *input2,
                        int bytes1_arg,
                        int bytes2_arg )
{
    psa_key_handle_t base_handle = 0;
    psa_key_handle_t derived_handle = 0;
    psa_algorithm_t alg = alg_arg;
    size_t bytes1 = bytes1_arg;
    size_t bytes2 = bytes2_arg;
    size_t capacity = bytes1 + bytes2;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    uint8_t *output_buffer = NULL;
    uint8_t *export_buffer = NULL;
    psa_key_attributes_t base_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t derived_attributes = PSA_KEY_ATTRIBUTES_INIT;
    size_t length;

    ASSERT_ALLOC( output_buffer, capacity );
    ASSERT_ALLOC( export_buffer, capacity );
    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &base_attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &base_attributes, alg );
    psa_set_key_type( &base_attributes, PSA_KEY_TYPE_DERIVE );
    PSA_ASSERT( psa_import_key( &base_attributes, key_data->x, key_data->len,
                                &base_handle ) );

    /* Derive some material and output it. */
    if( !setup_key_derivation_wrap( &operation, base_handle, alg,
                                    input1->x, input1->len,
                                    input2->x, input2->len, capacity ) )
        goto exit;

    PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                 output_buffer,
                                                 capacity ) );
    PSA_ASSERT( psa_key_derivation_abort( &operation ) );

    /* Derive the same output again, but this time store it in key objects. */
    if( !setup_key_derivation_wrap( &operation, base_handle, alg,
                                    input1->x, input1->len,
                                    input2->x, input2->len, capacity ) )
        goto exit;

    psa_set_key_usage_flags( &derived_attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_algorithm( &derived_attributes, 0 );
    psa_set_key_type( &derived_attributes, PSA_KEY_TYPE_RAW_DATA );
    psa_set_key_bits( &derived_attributes, PSA_BYTES_TO_BITS( bytes1 ) );
    PSA_ASSERT( psa_key_derivation_output_key( &derived_attributes, &operation,
                                               &derived_handle ) );
    PSA_ASSERT( psa_export_key( derived_handle,
                                export_buffer, bytes1,
                                &length ) );
    TEST_EQUAL( length, bytes1 );
    PSA_ASSERT( psa_destroy_key( derived_handle ) );
    psa_set_key_bits( &derived_attributes, PSA_BYTES_TO_BITS( bytes2 ) );
    PSA_ASSERT( psa_key_derivation_output_key( &derived_attributes, &operation,
                                               &derived_handle ) );
    PSA_ASSERT( psa_export_key( derived_handle,
                                export_buffer + bytes1, bytes2,
                                &length ) );
    TEST_EQUAL( length, bytes2 );

    /* Compare the outputs from the two runs. */
    ASSERT_COMPARE( output_buffer, bytes1 + bytes2,
                    export_buffer, capacity );

exit:
    mbedtls_free( output_buffer );
    mbedtls_free( export_buffer );
    psa_key_derivation_abort( &operation );
    psa_destroy_key( base_handle );
    psa_destroy_key( derived_handle );
    PSA_DONE( );
}

void test_derive_key_export_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};

    test_derive_key_export( *( (int *) params[0] ), &data1, &data3, &data5, *( (int *) params[7] ), *( (int *) params[8] ) );
}
#line 5041 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_derive_key( int alg_arg,
                 data_t *key_data, data_t *input1, data_t *input2,
                 int type_arg, int bits_arg,
                 int expected_status_arg )
{
    psa_key_handle_t base_handle = 0;
    psa_key_handle_t derived_handle = 0;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t type = type_arg;
    size_t bits = bits_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_attributes_t base_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t derived_attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &base_attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &base_attributes, alg );
    psa_set_key_type( &base_attributes, PSA_KEY_TYPE_DERIVE );
    PSA_ASSERT( psa_import_key( &base_attributes, key_data->x, key_data->len,
                                &base_handle ) );

    if( !setup_key_derivation_wrap( &operation, base_handle, alg,
                                    input1->x, input1->len,
                                    input2->x, input2->len, SIZE_MAX ) )
        goto exit;

    psa_set_key_usage_flags( &derived_attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_algorithm( &derived_attributes, 0 );
    psa_set_key_type( &derived_attributes, type );
    psa_set_key_bits( &derived_attributes, bits );
    TEST_EQUAL( psa_key_derivation_output_key( &derived_attributes, &operation,
                                               &derived_handle ),
                expected_status );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( base_handle );
    psa_destroy_key( derived_handle );
    PSA_DONE( );
}

void test_derive_key_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};

    test_derive_key( *( (int *) params[0] ), &data1, &data3, &data5, *( (int *) params[7] ), *( (int *) params[8] ), *( (int *) params[9] ) );
}
#line 5086 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_key_agreement_setup( int alg_arg,
                          int our_key_type_arg, data_t *our_key_data,
                          data_t *peer_key_data,
                          int expected_status_arg )
{
    psa_key_handle_t our_key = 0;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t our_key_type = our_key_type_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_status_t expected_status = expected_status_arg;
    psa_status_t status;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, our_key_type );
    PSA_ASSERT( psa_import_key( &attributes,
                                our_key_data->x, our_key_data->len,
                                &our_key ) );

    /* The tests currently include inputs that should fail at either step.
     * Test cases that fail at the setup step should be changed to call
     * key_derivation_setup instead, and this function should be renamed
     * to key_agreement_fail. */
    status = psa_key_derivation_setup( &operation, alg );
    if( status == PSA_SUCCESS )
    {
        TEST_EQUAL( psa_key_derivation_key_agreement(
                        &operation, PSA_KEY_DERIVATION_INPUT_SECRET,
                        our_key,
                        peer_key_data->x, peer_key_data->len ),
                    expected_status );
    }
    else
    {
        TEST_ASSERT( status == expected_status );
    }

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( our_key );
    PSA_DONE( );
}

void test_key_agreement_setup_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_key_agreement_setup( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, *( (int *) params[6] ) );
}
#line 5134 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_raw_key_agreement( int alg_arg,
                        int our_key_type_arg, data_t *our_key_data,
                        data_t *peer_key_data,
                        data_t *expected_output )
{
    psa_key_handle_t our_key = 0;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t our_key_type = our_key_type_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    unsigned char *output = NULL;
    size_t output_length = ~0;

    ASSERT_ALLOC( output, expected_output->len );
    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, our_key_type );
    PSA_ASSERT( psa_import_key( &attributes,
                                our_key_data->x, our_key_data->len,
                                &our_key ) );

    PSA_ASSERT( psa_raw_key_agreement( alg, our_key,
                                       peer_key_data->x, peer_key_data->len,
                                       output, expected_output->len,
                                       &output_length ) );
    ASSERT_COMPARE( output, output_length,
                    expected_output->x, expected_output->len );

exit:
    mbedtls_free( output );
    psa_destroy_key( our_key );
    PSA_DONE( );
}

void test_raw_key_agreement_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_raw_key_agreement( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6 );
}
#line 5171 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_key_agreement_capacity( int alg_arg,
                             int our_key_type_arg, data_t *our_key_data,
                             data_t *peer_key_data,
                             int expected_capacity_arg )
{
    psa_key_handle_t our_key = 0;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t our_key_type = our_key_type_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    size_t actual_capacity;
    unsigned char output[16];

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, our_key_type );
    PSA_ASSERT( psa_import_key( &attributes,
                                our_key_data->x, our_key_data->len,
                                &our_key ) );

    PSA_ASSERT( psa_key_derivation_setup( &operation, alg ) );
    PSA_ASSERT( psa_key_derivation_key_agreement(
                    &operation,
                    PSA_KEY_DERIVATION_INPUT_SECRET, our_key,
                    peer_key_data->x, peer_key_data->len ) );
    if( PSA_ALG_IS_HKDF( PSA_ALG_KEY_AGREEMENT_GET_KDF( alg ) ) )
    {
        /* The test data is for info="" */
        PSA_ASSERT( psa_key_derivation_input_bytes( &operation,
                                                    PSA_KEY_DERIVATION_INPUT_INFO,
                                                    NULL, 0 ) );
    }

    /* Test the advertized capacity. */
    PSA_ASSERT( psa_key_derivation_get_capacity(
                    &operation, &actual_capacity ) );
    TEST_EQUAL( actual_capacity, (size_t) expected_capacity_arg );

    /* Test the actual capacity by reading the output. */
    while( actual_capacity > sizeof( output ) )
    {
        PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                     output, sizeof( output ) ) );
        actual_capacity -= sizeof( output );
    }
    PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                 output, actual_capacity ) );
    TEST_EQUAL( psa_key_derivation_output_bytes( &operation, output, 1 ),
                PSA_ERROR_INSUFFICIENT_DATA );

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( our_key );
    PSA_DONE( );
}

void test_key_agreement_capacity_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};

    test_key_agreement_capacity( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, *( (int *) params[6] ) );
}
#line 5231 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_key_agreement_output( int alg_arg,
                           int our_key_type_arg, data_t *our_key_data,
                           data_t *peer_key_data,
                           data_t *expected_output1, data_t *expected_output2 )
{
    psa_key_handle_t our_key = 0;
    psa_algorithm_t alg = alg_arg;
    psa_key_type_t our_key_type = our_key_type_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    uint8_t *actual_output = NULL;

    ASSERT_ALLOC( actual_output, MAX( expected_output1->len,
                                      expected_output2->len ) );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_DERIVE );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, our_key_type );
    PSA_ASSERT( psa_import_key( &attributes,
                                our_key_data->x, our_key_data->len,
                                &our_key ) );

    PSA_ASSERT( psa_key_derivation_setup( &operation, alg ) );
    PSA_ASSERT( psa_key_derivation_key_agreement(
                    &operation,
                    PSA_KEY_DERIVATION_INPUT_SECRET, our_key,
                    peer_key_data->x, peer_key_data->len ) );
    if( PSA_ALG_IS_HKDF( PSA_ALG_KEY_AGREEMENT_GET_KDF( alg ) ) )
    {
        /* The test data is for info="" */
        PSA_ASSERT( psa_key_derivation_input_bytes( &operation,
                                                    PSA_KEY_DERIVATION_INPUT_INFO,
                                                    NULL, 0 ) );
    }

    PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                 actual_output,
                                                 expected_output1->len ) );
    ASSERT_COMPARE( actual_output, expected_output1->len,
                    expected_output1->x, expected_output1->len );
    if( expected_output2->len != 0 )
    {
        PSA_ASSERT( psa_key_derivation_output_bytes( &operation,
                                                     actual_output,
                                                     expected_output2->len ) );
        ASSERT_COMPARE( actual_output, expected_output2->len,
                        expected_output2->x, expected_output2->len );
    }

exit:
    psa_key_derivation_abort( &operation );
    psa_destroy_key( our_key );
    PSA_DONE( );
    mbedtls_free( actual_output );
}

void test_key_agreement_output_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};

    test_key_agreement_output( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, &data8 );
}
#line 5291 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_generate_random( int bytes_arg )
{
    size_t bytes = bytes_arg;
    const unsigned char trail[] = "don't overwrite me";
    unsigned char *output = NULL;
    unsigned char *changed = NULL;
    size_t i;
    unsigned run;

    ASSERT_ALLOC( output, bytes + sizeof( trail ) );
    ASSERT_ALLOC( changed, bytes );
    memcpy( output + bytes, trail, sizeof( trail ) );

    PSA_ASSERT( psa_crypto_init( ) );

    /* Run several times, to ensure that every output byte will be
     * nonzero at least once with overwhelming probability
     * (2^(-8*number_of_runs)). */
    for( run = 0; run < 10; run++ )
    {
        if( bytes != 0 )
            memset( output, 0, bytes );
        PSA_ASSERT( psa_generate_random( output, bytes ) );

        /* Check that no more than bytes have been overwritten */
        ASSERT_COMPARE( output + bytes, sizeof( trail ),
                        trail, sizeof( trail ) );

        for( i = 0; i < bytes; i++ )
        {
            if( output[i] != 0 )
                ++changed[i];
        }
    }

    /* Check that every byte was changed to nonzero at least once. This
     * validates that psa_generate_random is overwriting every byte of
     * the output buffer. */
    for( i = 0; i < bytes; i++ )
    {
        TEST_ASSERT( changed[i] != 0 );
    }

exit:
    PSA_DONE( );
    mbedtls_free( output );
    mbedtls_free( changed );
}

void test_generate_random_wrapper( void ** params )
{

    test_generate_random( *( (int *) params[0] ) );
}
#line 5342 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_generate_key( int type_arg,
                   int bits_arg,
                   int usage_arg,
                   int alg_arg,
                   int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t type = type_arg;
    psa_key_usage_t usage = usage_arg;
    size_t bits = bits_arg;
    psa_algorithm_t alg = alg_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t got_attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, usage );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );
    psa_set_key_bits( &attributes, bits );

    /* Generate a key */
    TEST_EQUAL( psa_generate_key( &attributes, &handle ), expected_status );
    if( expected_status != PSA_SUCCESS )
        goto exit;

    /* Test the key information */
    PSA_ASSERT( psa_get_key_attributes( handle, &got_attributes ) );
    TEST_EQUAL( psa_get_key_type( &got_attributes ), type );
    TEST_EQUAL( psa_get_key_bits( &got_attributes ), bits );

    /* Do something with the key according to its type and permitted usage. */
    if( ! exercise_key( handle, usage, alg ) )
        goto exit;

exit:
    psa_reset_key_attributes( &got_attributes );
    psa_destroy_key( handle );
    PSA_DONE( );
}

void test_generate_key_wrapper( void ** params )
{

    test_generate_key( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_GENPRIME)
#if defined(MBEDTLS_PKCS1_V15)
#line 5386 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_generate_key_rsa( int bits_arg,
                       data_t *e_arg,
                       int expected_status_arg )
{
    psa_key_handle_t handle = 0;
    psa_key_type_t type = PSA_KEY_TYPE_RSA_KEY_PAIR;
    size_t bits = bits_arg;
    psa_key_usage_t usage = PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT;
    psa_algorithm_t alg = PSA_ALG_RSA_PKCS1V15_SIGN_RAW;
    psa_status_t expected_status = expected_status_arg;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    uint8_t *exported = NULL;
    size_t exported_size =
        PSA_KEY_EXPORT_MAX_SIZE( PSA_KEY_TYPE_RSA_PUBLIC_KEY, bits );
    size_t exported_length = SIZE_MAX;
    uint8_t *e_read_buffer = NULL;
    int is_default_public_exponent = 0;
    size_t e_read_size = PSA_KEY_DOMAIN_PARAMETERS_SIZE( type, bits );
    size_t e_read_length = SIZE_MAX;

    if( e_arg->len == 0 ||
        ( e_arg->len == 3 &&
          e_arg->x[0] == 1 && e_arg->x[1] == 0 && e_arg->x[2] == 1 ) )
    {
        is_default_public_exponent = 1;
        e_read_size = 0;
    }
    ASSERT_ALLOC( e_read_buffer, e_read_size );
    ASSERT_ALLOC( exported, exported_size );

    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_usage_flags( &attributes, usage );
    psa_set_key_algorithm( &attributes, alg );
    PSA_ASSERT( psa_set_key_domain_parameters( &attributes, type,
                                               e_arg->x, e_arg->len ) );
    psa_set_key_bits( &attributes, bits );

    /* Generate a key */
    TEST_EQUAL( psa_generate_key( &attributes, &handle ), expected_status );
    if( expected_status != PSA_SUCCESS )
        goto exit;

    /* Test the key information */
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    TEST_EQUAL( psa_get_key_type( &attributes ), type );
    TEST_EQUAL( psa_get_key_bits( &attributes ), bits );
    PSA_ASSERT( psa_get_key_domain_parameters( &attributes,
                                               e_read_buffer, e_read_size,
                                               &e_read_length ) );
    if( is_default_public_exponent )
        TEST_EQUAL( e_read_length, 0 );
    else
        ASSERT_COMPARE( e_read_buffer, e_read_length, e_arg->x, e_arg->len );

    /* Do something with the key according to its type and permitted usage. */
    if( ! exercise_key( handle, usage, alg ) )
        goto exit;

    /* Export the key and check the public exponent. */
    PSA_ASSERT( psa_export_public_key( handle,
                                       exported, exported_size,
                                       &exported_length ) );
    {
        uint8_t *p = exported;
        uint8_t *end = exported + exported_length;
        size_t len;
        /*   RSAPublicKey ::= SEQUENCE {
         *      modulus            INTEGER,    -- n
         *      publicExponent     INTEGER  }  -- e
         */
        TEST_EQUAL( 0, mbedtls_asn1_get_tag( &p, end, &len,
                                             MBEDTLS_ASN1_SEQUENCE |
                                             MBEDTLS_ASN1_CONSTRUCTED ) );
        TEST_ASSERT( asn1_skip_integer( &p, end, bits, bits, 1 ) );
        TEST_EQUAL( 0, mbedtls_asn1_get_tag( &p, end, &len,
                                             MBEDTLS_ASN1_INTEGER ) );
        if( len >= 1 && p[0] == 0 )
        {
            ++p;
            --len;
        }
        if( e_arg->len == 0 )
        {
            TEST_EQUAL( len, 3 );
            TEST_EQUAL( p[0], 1 );
            TEST_EQUAL( p[1], 0 );
            TEST_EQUAL( p[2], 1 );
        }
        else
            ASSERT_COMPARE( p, len, e_arg->x, e_arg->len );
    }

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    PSA_DONE( );
    mbedtls_free( e_read_buffer );
    mbedtls_free( exported );
}

void test_generate_key_rsa_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};

    test_generate_key_rsa( *( (int *) params[0] ), &data1, *( (int *) params[3] ) );
}
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* MBEDTLS_GENPRIME */
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_PSA_CRYPTO_STORAGE_C)
#line 5489 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto.function"
void test_persistent_key_load_key_from_storage( data_t *data,
                                           int type_arg, int bits_arg,
                                           int usage_flags_arg, int alg_arg,
                                           int generation_method )
{
    psa_key_id_t key_id = 1;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t handle = 0;
    psa_key_handle_t base_key = 0;
    psa_key_type_t type = type_arg;
    size_t bits = bits_arg;
    psa_key_usage_t usage_flags = usage_flags_arg;
    psa_algorithm_t alg = alg_arg;
    psa_key_derivation_operation_t operation = PSA_KEY_DERIVATION_OPERATION_INIT;
    unsigned char *first_export = NULL;
    unsigned char *second_export = NULL;
    size_t export_size = PSA_KEY_EXPORT_MAX_SIZE( type, bits );
    size_t first_exported_length;
    size_t second_exported_length;

    if( usage_flags & PSA_KEY_USAGE_EXPORT )
    {
        ASSERT_ALLOC( first_export, export_size );
        ASSERT_ALLOC( second_export, export_size );
    }

    PSA_ASSERT( psa_crypto_init() );

    psa_set_key_id( &attributes, key_id );
    psa_set_key_usage_flags( &attributes, usage_flags );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );
    psa_set_key_bits( &attributes, bits );

    switch( generation_method )
    {
        case IMPORT_KEY:
            /* Import the key */
            PSA_ASSERT( psa_import_key( &attributes, data->x, data->len,
                                        &handle ) );
            break;

        case GENERATE_KEY:
            /* Generate a key */
            PSA_ASSERT( psa_generate_key( &attributes, &handle ) );
            break;

        case DERIVE_KEY:
            {
                /* Create base key */
                psa_algorithm_t derive_alg = PSA_ALG_HKDF( PSA_ALG_SHA_256 );
                psa_key_attributes_t base_attributes = PSA_KEY_ATTRIBUTES_INIT;
                psa_set_key_usage_flags( &base_attributes,
                                         PSA_KEY_USAGE_DERIVE );
                psa_set_key_algorithm( &base_attributes, derive_alg );
                psa_set_key_type( &base_attributes, PSA_KEY_TYPE_DERIVE );
                PSA_ASSERT( psa_import_key( &base_attributes,
                                            data->x, data->len,
                                            &base_key ) );
                /* Derive a key. */
                PSA_ASSERT( psa_key_derivation_setup( &operation, derive_alg ) );
                PSA_ASSERT( psa_key_derivation_input_key(
                                &operation,
                                PSA_KEY_DERIVATION_INPUT_SECRET, base_key ) );
                PSA_ASSERT( psa_key_derivation_input_bytes(
                                &operation, PSA_KEY_DERIVATION_INPUT_INFO,
                                NULL, 0 ) );
                PSA_ASSERT( psa_key_derivation_output_key( &attributes,
                                                           &operation,
                                                           &handle ) );
                PSA_ASSERT( psa_key_derivation_abort( &operation ) );
                PSA_ASSERT( psa_destroy_key( base_key ) );
                base_key = 0;
            }
        break;
    }
    psa_reset_key_attributes( &attributes );

    /* Export the key if permitted by the key policy. */
    if( usage_flags & PSA_KEY_USAGE_EXPORT )
    {
        PSA_ASSERT( psa_export_key( handle,
                                    first_export, export_size,
                                    &first_exported_length ) );
        if( generation_method == IMPORT_KEY )
            ASSERT_COMPARE( data->x, data->len,
                            first_export, first_exported_length );
    }

    /* Shutdown and restart */
    PSA_ASSERT( psa_close_key( handle ) );
    PSA_DONE();
    PSA_ASSERT( psa_crypto_init() );

    /* Check key slot still contains key data */
    PSA_ASSERT( psa_open_key( key_id, &handle ) );
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );
    TEST_EQUAL( psa_get_key_id( &attributes ), key_id );
    TEST_EQUAL( psa_get_key_lifetime( &attributes ),
                PSA_KEY_LIFETIME_PERSISTENT );
    TEST_EQUAL( psa_get_key_type( &attributes ), type );
    TEST_EQUAL( psa_get_key_bits( &attributes ), bits );
    TEST_EQUAL( psa_get_key_usage_flags( &attributes ), usage_flags );
    TEST_EQUAL( psa_get_key_algorithm( &attributes ), alg );

    /* Export the key again if permitted by the key policy. */
    if( usage_flags & PSA_KEY_USAGE_EXPORT )
    {
        PSA_ASSERT( psa_export_key( handle,
                                    second_export, export_size,
                                    &second_exported_length ) );
        ASSERT_COMPARE( first_export, first_exported_length,
                        second_export, second_exported_length );
    }

    /* Do something with the key according to its type and permitted usage. */
    if( ! exercise_key( handle, usage_flags, alg ) )
        goto exit;

exit:
    psa_reset_key_attributes( &attributes );
    mbedtls_free( first_export );
    mbedtls_free( second_export );
    psa_key_derivation_abort( &operation );
    psa_destroy_key( base_key );
    if( handle == 0 )
    {
        /* In case there was a test failure after creating the persistent key
         * but while it was not open, try to re-open the persistent key
         * to delete it. */
        psa_open_key( key_id, &handle );
    }
    psa_destroy_key( handle );
    PSA_DONE();
}

void test_persistent_key_load_key_from_storage_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_persistent_key_load_key_from_storage( &data0, *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ) );
}
#endif /* MBEDTLS_PSA_CRYPTO_STORAGE_C */
#endif /* MBEDTLS_PSA_CRYPTO_C */


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

#if defined(MBEDTLS_PSA_CRYPTO_C)

        case 0:
            {
                *out_value = PSA_KEY_LIFETIME_PERSISTENT;
            }
            break;
        case 1:
            {
                *out_value = PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT;
            }
            break;
        case 2:
            {
                *out_value = PSA_ALG_CCM;
            }
            break;
        case 3:
            {
                *out_value = PSA_KEY_TYPE_AES;
            }
            break;
        case 4:
            {
                *out_value = -1;
            }
            break;
        case 5:
            {
                *out_value = PSA_KEY_LIFETIME_VOLATILE;
            }
            break;
        case 6:
            {
                *out_value = PSA_KEY_TYPE_RAW_DATA;
            }
            break;
        case 7:
            {
                *out_value = PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 8:
            {
                *out_value = PSA_SUCCESS;
            }
            break;
        case 9:
            {
                *out_value = PSA_ERROR_BUFFER_TOO_SMALL;
            }
            break;
        case 10:
            {
                *out_value = PSA_ALG_CTR;
            }
            break;
        case 11:
            {
                *out_value = PSA_ERROR_INVALID_ARGUMENT;
            }
            break;
        case 12:
            {
                *out_value = PSA_KEY_TYPE_NONE;
            }
            break;
        case 13:
            {
                *out_value = PSA_ERROR_NOT_SUPPORTED;
            }
            break;
        case 14:
            {
                *out_value = PSA_KEY_TYPE_CATEGORY_MASK;
            }
            break;
        case 15:
            {
                *out_value = PSA_KEY_TYPE_RSA_PUBLIC_KEY;
            }
            break;
        case 16:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_SIGN_RAW;
            }
            break;
        case 17:
            {
                *out_value = PSA_KEY_TYPE_RSA_KEY_PAIR;
            }
            break;
        case 18:
            {
                *out_value = PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_CURVE_SECP_R1);
            }
            break;
        case 19:
            {
                *out_value = PSA_ALG_ECDSA_ANY;
            }
            break;
        case 20:
            {
                *out_value = PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_CURVE_BRAINPOOL_P_R1);
            }
            break;
        case 21:
            {
                *out_value = PSA_ALG_CBC_NO_PADDING;
            }
            break;
        case 22:
            {
                *out_value = PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_CURVE_SECP_R1);
            }
            break;
        case 23:
            {
                *out_value = PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_CURVE_BRAINPOOL_P_R1);
            }
            break;
        case 24:
            {
                *out_value = PSA_ERROR_NOT_PERMITTED;
            }
            break;
        case 25:
            {
                *out_value = PSA_KEY_TYPE_HMAC;
            }
            break;
        case 26:
            {
                *out_value = PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH;
            }
            break;
        case 27:
            {
                *out_value = PSA_ALG_HMAC(PSA_ALG_SHA_256);
            }
            break;
        case 28:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_CRYPT;
            }
            break;
        case 29:
            {
                *out_value = PSA_VENDOR_RSA_MAX_KEY_BITS+8;
            }
            break;
        case 30:
            {
                *out_value = PSA_KEY_USAGE_ENCRYPT;
            }
            break;
        case 31:
            {
                *out_value = PSA_KEY_TYPE_ECC_KEY_PAIR( PSA_ECC_CURVE_SECP_R1 );
            }
            break;
        case 32:
            {
                *out_value = PSA_KEY_USAGE_SIGN_HASH;
            }
            break;
        case 33:
            {
                *out_value = PSA_ALG_HMAC(PSA_ALG_SHA_224);
            }
            break;
        case 34:
            {
                *out_value = PSA_ALG_HMAC(PSA_ALG_ANY_HASH);
            }
            break;
        case 35:
            {
                *out_value = PSA_KEY_USAGE_VERIFY_HASH;
            }
            break;
        case 36:
            {
                *out_value = PSA_KEY_USAGE_DECRYPT;
            }
            break;
        case 37:
            {
                *out_value = PSA_ALG_GCM;
            }
            break;
        case 38:
            {
                *out_value = PSA_ALG_RSA_OAEP(PSA_ALG_SHA_256);
            }
            break;
        case 39:
            {
                *out_value = PSA_ALG_RSA_OAEP(PSA_ALG_SHA_224);
            }
            break;
        case 40:
            {
                *out_value = PSA_ALG_RSA_OAEP(PSA_ALG_ANY_HASH);
            }
            break;
        case 41:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_SIGN(PSA_ALG_SHA_256);
            }
            break;
        case 42:
            {
                *out_value = PSA_ALG_RSA_PSS(PSA_ALG_SHA_256);
            }
            break;
        case 43:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_SIGN(PSA_ALG_ANY_HASH);
            }
            break;
        case 44:
            {
                *out_value = PSA_ALG_ECDSA(PSA_ALG_ANY_HASH);
            }
            break;
        case 45:
            {
                *out_value = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
            }
            break;
        case 46:
            {
                *out_value = PSA_KEY_USAGE_DERIVE;
            }
            break;
        case 47:
            {
                *out_value = PSA_ALG_HKDF(PSA_ALG_SHA_256);
            }
            break;
        case 48:
            {
                *out_value = PSA_KEY_TYPE_DERIVE;
            }
            break;
        case 49:
            {
                *out_value = PSA_ALG_TLS12_PRF(PSA_ALG_SHA_256);
            }
            break;
        case 50:
            {
                *out_value = PSA_ALG_HKDF(PSA_ALG_SHA_224);
            }
            break;
        case 51:
            {
                *out_value = PSA_ALG_KEY_AGREEMENT(PSA_ALG_ECDH, PSA_ALG_HKDF(PSA_ALG_SHA_256));
            }
            break;
        case 52:
            {
                *out_value = PSA_ALG_KEY_AGREEMENT(PSA_ALG_FFDH, PSA_ALG_HKDF(PSA_ALG_SHA_256));
            }
            break;
        case 53:
            {
                *out_value = PSA_ALG_KEY_AGREEMENT(PSA_ALG_ECDH, PSA_ALG_HKDF(PSA_ALG_SHA_224));
            }
            break;
        case 54:
            {
                *out_value = PSA_ALG_ECDH;
            }
            break;
        case 55:
            {
                *out_value = PSA_ALG_FFDH;
            }
            break;
        case 56:
            {
                *out_value = PSA_KEY_USAGE_DERIVE | PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH;
            }
            break;
        case 57:
            {
                *out_value = PSA_KEY_USAGE_COPY;
            }
            break;
        case 58:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 59:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_ENCRYPT;
            }
            break;
        case 60:
            {
                *out_value = PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 61:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT;
            }
            break;
        case 62:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 63:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 64:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_SIGN_HASH;
            }
            break;
        case 65:
            {
                *out_value = PSA_KEY_USAGE_EXPORT | PSA_KEY_USAGE_VERIFY_HASH;
            }
            break;
        case 66:
            {
                *out_value = PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 67:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_DERIVE;
            }
            break;
        case 68:
            {
                *out_value = PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_DERIVE | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 69:
            {
                *out_value = PSA_KEY_USAGE_VERIFY_HASH | PSA_KEY_USAGE_DERIVE;
            }
            break;
        case 70:
            {
                *out_value = PSA_KEY_USAGE_COPY | PSA_KEY_USAGE_EXPORT;
            }
            break;
        case 71:
            {
                *out_value = PSA_ALG_RSA_PSS(PSA_ALG_ANY_HASH);
            }
            break;
        case 72:
            {
                *out_value = PSA_ALG_ECDSA(PSA_ALG_SHA_224);
            }
            break;
        case 73:
            {
                *out_value = PSA_ALG_SHA_1;
            }
            break;
        case 74:
            {
                *out_value = PSA_ALG_SHA_224;
            }
            break;
        case 75:
            {
                *out_value = PSA_ALG_SHA_256;
            }
            break;
        case 76:
            {
                *out_value = PSA_ALG_SHA_384;
            }
            break;
        case 77:
            {
                *out_value = PSA_ALG_SHA_512;
            }
            break;
        case 78:
            {
                *out_value = PSA_ALG_MD2;
            }
            break;
        case 79:
            {
                *out_value = PSA_ALG_MD4;
            }
            break;
        case 80:
            {
                *out_value = PSA_ALG_MD5;
            }
            break;
        case 81:
            {
                *out_value = PSA_ALG_RIPEMD160;
            }
            break;
        case 82:
            {
                *out_value = PSA_ALG_CATEGORY_HASH;
            }
            break;
        case 83:
            {
                *out_value = PSA_ALG_ANY_HASH;
            }
            break;
        case 84:
            {
                *out_value = PSA_ERROR_INVALID_SIGNATURE;
            }
            break;
        case 85:
            {
                *out_value = PSA_ALG_CMAC;
            }
            break;
        case 86:
            {
                *out_value = PSA_ALG_HMAC(0);
            }
            break;
        case 87:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC( PSA_ALG_HMAC( PSA_ALG_SHA_256 ), 1 );
            }
            break;
        case 88:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC( PSA_ALG_HMAC( PSA_ALG_SHA_256 ), 33 );
            }
            break;
        case 89:
            {
                *out_value = PSA_ALG_HMAC(PSA_ALG_MD5);
            }
            break;
        case 90:
            {
                *out_value = PSA_ALG_HMAC(PSA_ALG_SHA_384);
            }
            break;
        case 91:
            {
                *out_value = PSA_ALG_HMAC(PSA_ALG_SHA_512);
            }
            break;
        case 92:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_HMAC(PSA_ALG_SHA_224), 28);
            }
            break;
        case 93:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_HMAC(PSA_ALG_SHA_512), 64);
            }
            break;
        case 94:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_HMAC(PSA_ALG_SHA_224), 27);
            }
            break;
        case 95:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_HMAC(PSA_ALG_SHA_512), 63);
            }
            break;
        case 96:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_HMAC(PSA_ALG_SHA_224), 4);
            }
            break;
        case 97:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_HMAC(PSA_ALG_SHA_512), 4);
            }
            break;
        case 98:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_CMAC, 16);
            }
            break;
        case 99:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_CMAC, 15);
            }
            break;
        case 100:
            {
                *out_value = PSA_ALG_TRUNCATED_MAC(PSA_ALG_CMAC, 4);
            }
            break;
        case 101:
            {
                *out_value = PSA_ALG_CATEGORY_CIPHER;
            }
            break;
        case 102:
            {
                *out_value = PSA_KEY_TYPE_ARC4;
            }
            break;
        case 103:
            {
                *out_value = PSA_ALG_CBC_PKCS7;
            }
            break;
        case 104:
            {
                *out_value = PSA_KEY_TYPE_DES;
            }
            break;
        case 105:
            {
                *out_value = PSA_ERROR_BAD_STATE;
            }
            break;
        case 106:
            {
                *out_value = PSA_ALG_CHACHA20;
            }
            break;
        case 107:
            {
                *out_value = PSA_KEY_TYPE_CHACHA20;
            }
            break;
        case 108:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 4 );
            }
            break;
        case 109:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 6 );
            }
            break;
        case 110:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 8 );
            }
            break;
        case 111:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 10 );
            }
            break;
        case 112:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 12 );
            }
            break;
        case 113:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 14 );
            }
            break;
        case 114:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 16 );
            }
            break;
        case 115:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 0 );
            }
            break;
        case 116:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 2 );
            }
            break;
        case 117:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 15 );
            }
            break;
        case 118:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_CCM, 18 );
            }
            break;
        case 119:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_GCM, 4 );
            }
            break;
        case 120:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_GCM, 15 );
            }
            break;
        case 121:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_GCM, 16 );
            }
            break;
        case 122:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_GCM, 0 );
            }
            break;
        case 123:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_GCM, 2 );
            }
            break;
        case 124:
            {
                *out_value = PSA_ALG_AEAD_WITH_TAG_LENGTH( PSA_ALG_GCM, 18 );
            }
            break;
        case 125:
            {
                *out_value = PSA_ALG_CHACHA20_POLY1305;
            }
            break;
        case 126:
            {
                *out_value = PSA_ALG_RSA_PSS( PSA_ALG_SHA_256 );
            }
            break;
        case 127:
            {
                *out_value = PSA_ALG_DETERMINISTIC_ECDSA( PSA_ALG_SHA_256 );
            }
            break;
        case 128:
            {
                *out_value = PSA_ALG_DETERMINISTIC_ECDSA( PSA_ALG_SHA_384 );
            }
            break;
        case 129:
            {
                *out_value = PSA_ALG_DETERMINISTIC_ECDSA( 0 );
            }
            break;
        case 130:
            {
                *out_value = PSA_ALG_DETERMINISTIC_ECDSA( PSA_ALG_ANY_HASH );
            }
            break;
        case 131:
            {
                *out_value = PSA_ALG_ECDSA( PSA_ALG_SHA_256 );
            }
            break;
        case 132:
            {
                *out_value = PSA_ALG_ECDSA( PSA_ALG_SHA_384 );
            }
            break;
        case 133:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_SIGN(PSA_ALG_SHA_1);
            }
            break;
        case 134:
            {
                *out_value = PSA_ALG_RSA_OAEP(PSA_ALG_SHA_384);
            }
            break;
        case 135:
            {
                *out_value = PSA_ERROR_INVALID_PADDING;
            }
            break;
        case 136:
            {
                *out_value = PSA_ALG_HKDF(PSA_ALG_SHA_512);
            }
            break;
        case 137:
            {
                *out_value = PSA_ALG_HKDF(PSA_ALG_CATEGORY_HASH);
            }
            break;
        case 138:
            {
                *out_value = PSA_ALG_CATEGORY_KEY_DERIVATION;
            }
            break;
        case 139:
            {
                *out_value = PSA_KEY_DERIVATION_INPUT_SALT;
            }
            break;
        case 140:
            {
                *out_value = PSA_KEY_DERIVATION_INPUT_SECRET;
            }
            break;
        case 141:
            {
                *out_value = PSA_KEY_DERIVATION_INPUT_INFO;
            }
            break;
        case 142:
            {
                *out_value = PSA_KEY_DERIVATION_INPUT_SEED;
            }
            break;
        case 143:
            {
                *out_value = PSA_KEY_DERIVATION_INPUT_LABEL;
            }
            break;
        case 144:
            {
                *out_value = PSA_ALG_TLS12_PSK_TO_MS(PSA_ALG_SHA_256);
            }
            break;
        case 145:
            {
                *out_value = PSA_ALG_HKDF(PSA_ALG_SHA_1);
            }
            break;
        case 146:
            {
                *out_value = PSA_ALG_TLS12_PRF(PSA_ALG_SHA_384);
            }
            break;
        case 147:
            {
                *out_value = PSA_ALG_TLS12_PSK_TO_MS(PSA_ALG_SHA_384);
            }
            break;
        case 148:
            {
                *out_value = 255 * 32;
            }
            break;
        case 149:
            {
                *out_value = 255 * 20;
            }
            break;
        case 150:
            {
                *out_value = 255 * 32 + 1;
            }
            break;
        case 151:
            {
                *out_value = 255 * 20 + 1;
            }
            break;
        case 152:
            {
                *out_value = 255 * 32 - 1;
            }
            break;
        case 153:
            {
                *out_value = PSA_MAX_KEY_BITS;
            }
            break;
        case 154:
            {
                *out_value = PSA_MAX_KEY_BITS + 1;
            }
            break;
        case 155:
            {
                *out_value = PSA_ALG_KEY_AGREEMENT(PSA_ALG_ECDH, PSA_ALG_HKDF(0));
            }
            break;
        case 156:
            {
                *out_value = PSA_ALG_KEY_AGREEMENT(0, PSA_ALG_HKDF(PSA_ALG_SHA_256));
            }
            break;
        case 157:
            {
                *out_value = MBEDTLS_CTR_DRBG_MAX_REQUEST;
            }
            break;
        case 158:
            {
                *out_value = MBEDTLS_CTR_DRBG_MAX_REQUEST + 1;
            }
            break;
        case 159:
            {
                *out_value = 2 * MBEDTLS_CTR_DRBG_MAX_REQUEST + 1;
            }
            break;
        case 160:
            {
                *out_value = (MBEDTLS_CTR_DRBG_MAX_REQUEST + 1) * 8;
            }
            break;
        case 161:
            {
                *out_value = (2 * MBEDTLS_CTR_DRBG_MAX_REQUEST + 1) * 8;
            }
            break;
        case 162:
            {
                *out_value = PSA_KEY_USAGE_EXPORT | PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT;
            }
            break;
        case 163:
            {
                *out_value = PSA_KEY_USAGE_EXPORT | PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH;
            }
            break;
        case 164:
            {
                *out_value = PSA_VENDOR_RSA_MAX_KEY_BITS+1;
            }
            break;
        case 165:
            {
                *out_value = IMPORT_KEY;
            }
            break;
        case 166:
            {
                *out_value = GENERATE_KEY;
            }
            break;
        case 167:
            {
                *out_value = DERIVE_KEY;
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

#if defined(MBEDTLS_PSA_CRYPTO_C)

        case 0:
            {
#if defined(MBEDTLS_AES_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
            {
#if defined(MBEDTLS_PK_PARSE_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 2:
            {
#if defined(MBEDTLS_PK_WRITE_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 3:
            {
#if defined(MBEDTLS_RSA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 4:
            {
#if defined(MBEDTLS_ECP_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 5:
            {
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 6:
            {
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 7:
            {
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 8:
            {
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 9:
            {
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 10:
            {
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 11:
            {
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 12:
            {
#if defined(MBEDTLS_CIPHER_MODE_CTR)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 13:
            {
#if defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 14:
            {
#if defined(MBEDTLS_PKCS1_V15)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 15:
            {
#if defined(MBEDTLS_MD_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 16:
            {
#if defined(MBEDTLS_PEM_PARSE_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 17:
            {
#if defined(HAVE_RAM_AVAILABLE_128K)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 18:
            {
#if defined(MBEDTLS_CIPHER_MODE_CBC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 19:
            {
#if defined(MBEDTLS_CCM_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 20:
            {
#if defined(MBEDTLS_GCM_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 21:
            {
#if defined(MBEDTLS_PKCS1_V21)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 22:
            {
#if defined(MBEDTLS_ECDSA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 23:
            {
#if defined(MBEDTLS_ECDH_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 24:
            {
#if defined(MBEDTLS_CIPHER_MODE_CBC_NOPAD)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 25:
            {
#if defined(MBEDTLS_SHA1_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 26:
            {
#if defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 27:
            {
#if !defined(MBEDTLS_SHA512_NO_SHA384)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 28:
            {
#if defined(MBEDTLS_MD2_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 29:
            {
#if defined(MBEDTLS_MD4_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 30:
            {
#if defined(MBEDTLS_MD5_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 31:
            {
#if defined(MBEDTLS_RIPEMD160_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 32:
            {
#if defined(MBEDTLS_CMAC_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 33:
            {
#if !defined(MBEDTLS_MD5_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 34:
            {
#if defined(MBEDTLS_ARC4_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 35:
            {
#if defined(MBEDTLS_DES_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 36:
            {
#if defined(MBEDTLS_CIPHER_PADDING_PKCS7)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 37:
            {
#if defined(MBEDTLS_CHACHA20_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 38:
            {
#if defined(MBEDTLS_CHACHAPOLY_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 39:
            {
#if defined(MBEDTLS_ECDSA_DETERMINISTIC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 40:
            {
#if defined(MBEDTLS_GENPRIME)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 41:
            {
#if defined(MBEDTLS_PK_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 42:
            {
#if defined(MBEDTLS_PSA_CRYPTO_STORAGE_C)
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

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_static_checks_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_attributes_set_get_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_persistence_attributes_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_slot_number_attribute_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_with_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 5 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_with_data_wrapper,
#else
    NULL,
#endif
/* Function Id: 6 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_large_key_wrapper,
#else
    NULL,
#endif
/* Function Id: 7 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_rsa_made_up_wrapper,
#else
    NULL,
#endif
/* Function Id: 8 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_export_wrapper,
#else
    NULL,
#endif
/* Function Id: 9 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_export_public_key_wrapper,
#else
    NULL,
#endif
/* Function Id: 10 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_import_and_exercise_key_wrapper,
#else
    NULL,
#endif
/* Function Id: 11 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_effective_key_attributes_wrapper,
#else
    NULL,
#endif
/* Function Id: 12 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_check_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 13 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_key_attributes_init_wrapper,
#else
    NULL,
#endif
/* Function Id: 14 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_mac_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 15 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 16 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_aead_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 17 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_encryption_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 18 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_signature_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 19 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 20 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_agreement_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 21 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_key_policy_alg2_wrapper,
#else
    NULL,
#endif
/* Function Id: 22 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_raw_agreement_key_policy_wrapper,
#else
    NULL,
#endif
/* Function Id: 23 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_copy_success_wrapper,
#else
    NULL,
#endif
/* Function Id: 24 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_copy_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 25 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_hash_operation_init_wrapper,
#else
    NULL,
#endif
/* Function Id: 26 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_hash_setup_wrapper,
#else
    NULL,
#endif
/* Function Id: 27 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_hash_compute_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 28 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_hash_compare_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 29 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_hash_compute_compare_wrapper,
#else
    NULL,
#endif
/* Function Id: 30 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_hash_bad_order_wrapper,
#else
    NULL,
#endif
/* Function Id: 31 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_SHA256_C)
    test_hash_verify_bad_args_wrapper,
#else
    NULL,
#endif
/* Function Id: 32 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_SHA256_C)
    test_hash_finish_bad_args_wrapper,
#else
    NULL,
#endif
/* Function Id: 33 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_SHA256_C)
    test_hash_clone_source_state_wrapper,
#else
    NULL,
#endif
/* Function Id: 34 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_SHA256_C)
    test_hash_clone_target_state_wrapper,
#else
    NULL,
#endif
/* Function Id: 35 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_mac_operation_init_wrapper,
#else
    NULL,
#endif
/* Function Id: 36 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_mac_setup_wrapper,
#else
    NULL,
#endif
/* Function Id: 37 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_mac_bad_order_wrapper,
#else
    NULL,
#endif
/* Function Id: 38 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_mac_sign_wrapper,
#else
    NULL,
#endif
/* Function Id: 39 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_mac_verify_wrapper,
#else
    NULL,
#endif
/* Function Id: 40 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_operation_init_wrapper,
#else
    NULL,
#endif
/* Function Id: 41 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_setup_wrapper,
#else
    NULL,
#endif
/* Function Id: 42 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_bad_order_wrapper,
#else
    NULL,
#endif
/* Function Id: 43 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_encrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 44 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_encrypt_multipart_wrapper,
#else
    NULL,
#endif
/* Function Id: 45 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_decrypt_multipart_wrapper,
#else
    NULL,
#endif
/* Function Id: 46 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_decrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 47 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_verify_output_wrapper,
#else
    NULL,
#endif
/* Function Id: 48 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_cipher_verify_output_multipart_wrapper,
#else
    NULL,
#endif
/* Function Id: 49 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_aead_encrypt_decrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 50 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_aead_encrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 51 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_aead_decrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 52 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_signature_size_wrapper,
#else
    NULL,
#endif
/* Function Id: 53 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_sign_deterministic_wrapper,
#else
    NULL,
#endif
/* Function Id: 54 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_sign_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 55 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_sign_verify_wrapper,
#else
    NULL,
#endif
/* Function Id: 56 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_verify_wrapper,
#else
    NULL,
#endif
/* Function Id: 57 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_verify_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 58 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_encrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 59 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_encrypt_decrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 60 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_decrypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 61 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_asymmetric_decrypt_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 62 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_key_derivation_init_wrapper,
#else
    NULL,
#endif
/* Function Id: 63 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_setup_wrapper,
#else
    NULL,
#endif
/* Function Id: 64 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_set_capacity_wrapper,
#else
    NULL,
#endif
/* Function Id: 65 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_input_wrapper,
#else
    NULL,
#endif
/* Function Id: 66 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_test_derive_invalid_key_derivation_state_wrapper,
#else
    NULL,
#endif
/* Function Id: 67 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_test_derive_invalid_key_derivation_tests_wrapper,
#else
    NULL,
#endif
/* Function Id: 68 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_output_wrapper,
#else
    NULL,
#endif
/* Function Id: 69 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_full_wrapper,
#else
    NULL,
#endif
/* Function Id: 70 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_key_exercise_wrapper,
#else
    NULL,
#endif
/* Function Id: 71 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_key_export_wrapper,
#else
    NULL,
#endif
/* Function Id: 72 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_derive_key_wrapper,
#else
    NULL,
#endif
/* Function Id: 73 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_key_agreement_setup_wrapper,
#else
    NULL,
#endif
/* Function Id: 74 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_raw_key_agreement_wrapper,
#else
    NULL,
#endif
/* Function Id: 75 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_key_agreement_capacity_wrapper,
#else
    NULL,
#endif
/* Function Id: 76 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_key_agreement_output_wrapper,
#else
    NULL,
#endif
/* Function Id: 77 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_generate_random_wrapper,
#else
    NULL,
#endif
/* Function Id: 78 */

#if defined(MBEDTLS_PSA_CRYPTO_C)
    test_generate_key_wrapper,
#else
    NULL,
#endif
/* Function Id: 79 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_GENPRIME) && defined(MBEDTLS_PKCS1_V15)
    test_generate_key_rsa_wrapper,
#else
    NULL,
#endif
/* Function Id: 80 */

#if defined(MBEDTLS_PSA_CRYPTO_C) && defined(MBEDTLS_PSA_CRYPTO_STORAGE_C)
    test_persistent_key_load_key_from_storage_wrapper,
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
    const char *default_filename = "./test_suite_psa_crypto.datax";
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
