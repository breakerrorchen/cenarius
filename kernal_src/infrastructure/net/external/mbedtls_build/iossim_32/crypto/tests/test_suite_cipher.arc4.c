#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_cipher.arc4.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/main_test.function
 *      Platform code file  : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/host_test.function
 *      Helper file         : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/helpers.function
 *      Test suite file     : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function
 *      Test suite data     : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.arc4.data
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

#if defined(MBEDTLS_CIPHER_C)
#line 2 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
#include "mbedtls/cipher.h"

#if defined(MBEDTLS_AES_C)
#include "mbedtls/aes.h"
#endif

#if defined(MBEDTLS_GCM_C)
#include "mbedtls/gcm.h"
#endif

#if defined(MBEDTLS_USE_PSA_CRYPTO)
#include "psa_crypto_helpers.h"
#endif

#line 24 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_mbedtls_cipher_list(  )
{
    const int *cipher_type;

    for( cipher_type = mbedtls_cipher_list(); *cipher_type != 0; cipher_type++ )
        TEST_ASSERT( mbedtls_cipher_info_from_type( *cipher_type ) != NULL );
exit:
    ;
}

void test_mbedtls_cipher_list_wrapper( void ** params )
{
    (void)params;

    test_mbedtls_cipher_list(  );
}
#line 34 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_cipher_invalid_param_unconditional( )
{
    mbedtls_cipher_context_t valid_ctx;
    mbedtls_cipher_context_t invalid_ctx;
    mbedtls_operation_t valid_operation = MBEDTLS_ENCRYPT;
    mbedtls_cipher_padding_t valid_mode = MBEDTLS_PADDING_ZEROS;
    unsigned char valid_buffer[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
    int valid_size = sizeof(valid_buffer);
    int valid_bitlen = valid_size * 8;
    const mbedtls_cipher_info_t *valid_info = mbedtls_cipher_info_from_type(
        *( mbedtls_cipher_list() ) );
    size_t size_t_var;

    (void)valid_mode; /* In some configurations this is unused */

    mbedtls_cipher_init( &valid_ctx );
    mbedtls_cipher_setup( &valid_ctx, valid_info );
    mbedtls_cipher_init( &invalid_ctx );

    /* mbedtls_cipher_setup() */
    TEST_ASSERT( mbedtls_cipher_setup( &valid_ctx, NULL ) ==
                 MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

    /* mbedtls_cipher_get_block_size() */
    TEST_ASSERT( mbedtls_cipher_get_block_size( &invalid_ctx ) == 0 );

    /* mbedtls_cipher_get_cipher_mode() */
    TEST_ASSERT( mbedtls_cipher_get_cipher_mode( &invalid_ctx ) ==
                 MBEDTLS_MODE_NONE );

    /* mbedtls_cipher_get_iv_size() */
    TEST_ASSERT( mbedtls_cipher_get_iv_size( &invalid_ctx ) == 0 );

    /* mbedtls_cipher_get_type() */
    TEST_ASSERT(
        mbedtls_cipher_get_type( &invalid_ctx ) ==
        MBEDTLS_CIPHER_NONE);

    /* mbedtls_cipher_get_name() */
    TEST_ASSERT( mbedtls_cipher_get_name( &invalid_ctx ) == 0 );

    /* mbedtls_cipher_get_key_bitlen() */
    TEST_ASSERT( mbedtls_cipher_get_key_bitlen( &invalid_ctx ) ==
                 MBEDTLS_KEY_LENGTH_NONE );

    /* mbedtls_cipher_get_operation() */
    TEST_ASSERT( mbedtls_cipher_get_operation( &invalid_ctx ) ==
                 MBEDTLS_OPERATION_NONE );

    /* mbedtls_cipher_setkey() */
    TEST_ASSERT(
        mbedtls_cipher_setkey( &invalid_ctx,
                               valid_buffer,
                               valid_bitlen,
                               valid_operation ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

    /* mbedtls_cipher_set_iv() */
    TEST_ASSERT(
        mbedtls_cipher_set_iv( &invalid_ctx,
                               valid_buffer,
                               valid_size ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

    /* mbedtls_cipher_reset() */
    TEST_ASSERT( mbedtls_cipher_reset( &invalid_ctx ) ==
                 MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    /* mbedtls_cipher_update_ad() */
    TEST_ASSERT(
        mbedtls_cipher_update_ad( &invalid_ctx,
                                  valid_buffer,
                                  valid_size ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );
#endif /* defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C) */

#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    /* mbedtls_cipher_set_padding_mode() */
    TEST_ASSERT( mbedtls_cipher_set_padding_mode( &invalid_ctx, valid_mode ) ==
                 MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );
#endif

    /* mbedtls_cipher_update() */
    TEST_ASSERT(
        mbedtls_cipher_update( &invalid_ctx,
                               valid_buffer,
                               valid_size,
                               valid_buffer,
                               &size_t_var ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

    /* mbedtls_cipher_finish() */
    TEST_ASSERT(
        mbedtls_cipher_finish( &invalid_ctx,
                               valid_buffer,
                               &size_t_var ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    /* mbedtls_cipher_write_tag() */
    TEST_ASSERT(
        mbedtls_cipher_write_tag( &invalid_ctx,
                                  valid_buffer,
                                  valid_size ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

    /* mbedtls_cipher_check_tag() */
    TEST_ASSERT(
        mbedtls_cipher_check_tag( &invalid_ctx,
                                  valid_buffer,
                                  valid_size ) ==
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );
#endif /* defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C) */

exit:
    mbedtls_cipher_free( &invalid_ctx );
    mbedtls_cipher_free( &valid_ctx );
}

void test_cipher_invalid_param_unconditional_wrapper( void ** params )
{
    (void)params;

    test_cipher_invalid_param_unconditional(  );
}
#if defined(MBEDTLS_CHECK_PARAMS)
#if !defined(MBEDTLS_PARAM_FAILED_ALT)
#line 156 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_cipher_invalid_param_conditional( )
{
    mbedtls_cipher_context_t valid_ctx;

    mbedtls_operation_t valid_operation = MBEDTLS_ENCRYPT;
    mbedtls_operation_t invalid_operation = 100;
    mbedtls_cipher_padding_t valid_mode = MBEDTLS_PADDING_ZEROS;
    unsigned char valid_buffer[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
    int valid_size = sizeof(valid_buffer);
    int valid_bitlen = valid_size * 8;
    const mbedtls_cipher_info_t *valid_info = mbedtls_cipher_info_from_type(
        *( mbedtls_cipher_list() ) );

    size_t size_t_var;

    (void)valid_mode; /* In some configurations this is unused */

    /* mbedtls_cipher_init() */
    TEST_VALID_PARAM( mbedtls_cipher_init( &valid_ctx ) );
    TEST_INVALID_PARAM( mbedtls_cipher_init( NULL ) );

    /* mbedtls_cipher_setup() */
    TEST_VALID_PARAM( mbedtls_cipher_setup( &valid_ctx, valid_info ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_setup( NULL, valid_info ) );

    /* mbedtls_cipher_get_block_size() */
    TEST_INVALID_PARAM_RET( 0, mbedtls_cipher_get_block_size( NULL ) );

    /* mbedtls_cipher_get_cipher_mode() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_MODE_NONE,
        mbedtls_cipher_get_cipher_mode( NULL ) );

    /* mbedtls_cipher_get_iv_size() */
    TEST_INVALID_PARAM_RET( 0, mbedtls_cipher_get_iv_size( NULL ) );

    /* mbedtls_cipher_get_type() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_CIPHER_NONE,
        mbedtls_cipher_get_type( NULL ) );

    /* mbedtls_cipher_get_name() */
    TEST_INVALID_PARAM_RET( 0, mbedtls_cipher_get_name( NULL ) );

    /* mbedtls_cipher_get_key_bitlen() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_KEY_LENGTH_NONE,
        mbedtls_cipher_get_key_bitlen( NULL ) );

    /* mbedtls_cipher_get_operation() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_OPERATION_NONE,
        mbedtls_cipher_get_operation( NULL ) );

    /* mbedtls_cipher_setkey() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_setkey( NULL,
                               valid_buffer,
                               valid_bitlen,
                               valid_operation ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_setkey( &valid_ctx,
                               NULL,
                               valid_bitlen,
                               valid_operation ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_setkey( &valid_ctx,
                               valid_buffer,
                               valid_bitlen,
                               invalid_operation ) );

    /* mbedtls_cipher_set_iv() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_set_iv( NULL,
                               valid_buffer,
                               valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_set_iv( &valid_ctx,
                               NULL,
                               valid_size ) );

    /* mbedtls_cipher_reset() */
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
                            mbedtls_cipher_reset( NULL ) );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    /* mbedtls_cipher_update_ad() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_update_ad( NULL,
                                  valid_buffer,
                                  valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_update_ad( &valid_ctx,
                                  NULL,
                                  valid_size ) );
#endif /* defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C) */

#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    /* mbedtls_cipher_set_padding_mode() */
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
                            mbedtls_cipher_set_padding_mode( NULL, valid_mode ) );
#endif

    /* mbedtls_cipher_update() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_update( NULL,
                               valid_buffer,
                               valid_size,
                               valid_buffer,
                               &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_update( &valid_ctx,
                               NULL, valid_size,
                               valid_buffer,
                               &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_update( &valid_ctx,
                               valid_buffer, valid_size,
                               NULL,
                               &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_update( &valid_ctx,
                               valid_buffer, valid_size,
                               valid_buffer,
                               NULL ) );

    /* mbedtls_cipher_finish() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_finish( NULL,
                               valid_buffer,
                               &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_finish( &valid_ctx,
                               NULL,
                               &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_finish( &valid_ctx,
                               valid_buffer,
                               NULL ) );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    /* mbedtls_cipher_write_tag() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_write_tag( NULL,
                                  valid_buffer,
                                  valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_write_tag( &valid_ctx,
                                  NULL,
                                  valid_size ) );

    /* mbedtls_cipher_check_tag() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_check_tag( NULL,
                                  valid_buffer,
                                  valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_check_tag( &valid_ctx,
                                  NULL,
                                  valid_size ) );
#endif /* defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C) */

    /* mbedtls_cipher_crypt() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_crypt( NULL,
                              valid_buffer, valid_size,
                              valid_buffer, valid_size,
                              valid_buffer, &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_crypt( &valid_ctx,
                              NULL, valid_size,
                              valid_buffer, valid_size,
                              valid_buffer, &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_crypt( &valid_ctx,
                              valid_buffer, valid_size,
                              NULL, valid_size,
                              valid_buffer, &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_crypt( &valid_ctx,
                              valid_buffer, valid_size,
                              valid_buffer, valid_size,
                              NULL, &size_t_var ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_crypt( &valid_ctx,
                              valid_buffer, valid_size,
                              valid_buffer, valid_size,
                              valid_buffer, NULL ) );

#if defined(MBEDTLS_CIPHER_MODE_AEAD)
    /* mbedtls_cipher_auth_encrypt() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( NULL,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( &valid_ctx,
                                     NULL, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     NULL, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     NULL, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     NULL, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, NULL,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_encrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     NULL, valid_size ) );

    /* mbedtls_cipher_auth_decrypt() */
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( NULL,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( &valid_ctx,
                                     NULL, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     NULL, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     NULL, valid_size,
                                     valid_buffer, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     NULL, &size_t_var,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, NULL,
                                     valid_buffer, valid_size ) );
    TEST_INVALID_PARAM_RET(
        MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA,
        mbedtls_cipher_auth_decrypt( &valid_ctx,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, valid_size,
                                     valid_buffer, &size_t_var,
                                     NULL, valid_size ) );
#endif /* defined(MBEDTLS_CIPHER_MODE_AEAD) */

    /* mbedtls_cipher_free() */
    TEST_VALID_PARAM( mbedtls_cipher_free( NULL ) );
exit:
    TEST_VALID_PARAM( mbedtls_cipher_free( &valid_ctx ) );
}

void test_cipher_invalid_param_conditional_wrapper( void ** params )
{
    (void)params;

    test_cipher_invalid_param_conditional(  );
}
#endif /* !MBEDTLS_PARAM_FAILED_ALT */
#endif /* MBEDTLS_CHECK_PARAMS */
#if defined(MBEDTLS_AES_C)
#line 496 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_cipher_special_behaviours(  )
{
    const mbedtls_cipher_info_t *cipher_info;
    mbedtls_cipher_context_t ctx;
    unsigned char input[32];
    unsigned char output[32];
#if defined (MBEDTLS_CIPHER_MODE_CBC)
    unsigned char iv[32];
#endif
    size_t olen = 0;

    mbedtls_cipher_init( &ctx );
    memset( input, 0, sizeof( input ) );
    memset( output, 0, sizeof( output ) );
#if defined(MBEDTLS_CIPHER_MODE_CBC)
    memset( iv, 0, sizeof( iv ) );

    /* Check and get info structures */
    cipher_info = mbedtls_cipher_info_from_type( MBEDTLS_CIPHER_AES_128_CBC );
    TEST_ASSERT( NULL != cipher_info );

    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx, cipher_info ) );

    /* IV too big */
    TEST_ASSERT( mbedtls_cipher_set_iv( &ctx, iv, MBEDTLS_MAX_IV_LENGTH + 1 )
                 == MBEDTLS_ERR_CIPHER_FEATURE_UNAVAILABLE );

    /* IV too small */
    TEST_ASSERT( mbedtls_cipher_set_iv( &ctx, iv, 0 )
                 == MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA );

    mbedtls_cipher_free( &ctx );
    mbedtls_cipher_init( &ctx );
#endif /* MBEDTLS_CIPHER_MODE_CBC */
    cipher_info = mbedtls_cipher_info_from_type( MBEDTLS_CIPHER_AES_128_ECB );
    TEST_ASSERT( NULL != cipher_info );

    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx, cipher_info ) );

    /* Update ECB with partial block */
    TEST_ASSERT( mbedtls_cipher_update( &ctx, input, 1, output, &olen )
                 == MBEDTLS_ERR_CIPHER_FULL_BLOCK_EXPECTED );

exit:
    mbedtls_cipher_free( &ctx );
}

void test_cipher_special_behaviours_wrapper( void ** params )
{
    (void)params;

    test_cipher_special_behaviours(  );
}
#endif /* MBEDTLS_AES_C */
#line 545 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_enc_dec_buf( int cipher_id, char * cipher_string, int key_len,
                  int length_val, int pad_mode )
{
    size_t length = length_val, outlen, total_len, i, block_size;
    unsigned char key[64];
    unsigned char iv[16];
    unsigned char ad[13];
    unsigned char tag[16];
    unsigned char inbuf[64];
    unsigned char encbuf[64];
    unsigned char decbuf[64];

    const mbedtls_cipher_info_t *cipher_info;
    mbedtls_cipher_context_t ctx_dec;
    mbedtls_cipher_context_t ctx_enc;

    /*
     * Prepare contexts
     */
    mbedtls_cipher_init( &ctx_dec );
    mbedtls_cipher_init( &ctx_enc );

    memset( key, 0x2a, sizeof( key ) );

    /* Check and get info structures */
    cipher_info = mbedtls_cipher_info_from_type( cipher_id );
    TEST_ASSERT( NULL != cipher_info );
    TEST_ASSERT( mbedtls_cipher_info_from_string( cipher_string ) == cipher_info );

    /* Initialise enc and dec contexts */
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx_dec, cipher_info ) );
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx_enc, cipher_info ) );

    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx_dec, key, key_len, MBEDTLS_DECRYPT ) );
    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx_enc, key, key_len, MBEDTLS_ENCRYPT ) );

#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    if( -1 != pad_mode )
    {
        TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx_dec, pad_mode ) );
        TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx_enc, pad_mode ) );
    }
#else
    (void) pad_mode;
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */

    /*
     * Do a few encode/decode cycles
     */
    for( i = 0; i < 3; i++ )
    {
    memset( iv , 0x00 + i, sizeof( iv ) );
    memset( ad, 0x10 + i, sizeof( ad ) );
    memset( inbuf, 0x20 + i, sizeof( inbuf ) );

    memset( encbuf, 0, sizeof( encbuf ) );
    memset( decbuf, 0, sizeof( decbuf ) );
    memset( tag, 0, sizeof( tag ) );

    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx_dec, iv, sizeof( iv ) ) );
    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx_enc, iv, sizeof( iv ) ) );

    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx_dec ) );
    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx_enc ) );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx_dec, ad, sizeof( ad ) - i ) );
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx_enc, ad, sizeof( ad ) - i ) );
#endif

    block_size = mbedtls_cipher_get_block_size( &ctx_enc );
    TEST_ASSERT( block_size != 0 );

    /* encode length number of bytes from inbuf */
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx_enc, inbuf, length, encbuf, &outlen ) );
    total_len = outlen;

    TEST_ASSERT( total_len == length ||
                 ( total_len % block_size == 0 &&
                   total_len < length &&
                   total_len + block_size > length ) );

    TEST_ASSERT( 0 == mbedtls_cipher_finish( &ctx_enc, encbuf + outlen, &outlen ) );
    total_len += outlen;

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_write_tag( &ctx_enc, tag, sizeof( tag ) ) );
#endif

    TEST_ASSERT( total_len == length ||
                 ( total_len % block_size == 0 &&
                   total_len > length &&
                   total_len <= length + block_size ) );

    /* decode the previously encoded string */
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx_dec, encbuf, total_len, decbuf, &outlen ) );
    total_len = outlen;

    TEST_ASSERT( total_len == length ||
                 ( total_len % block_size == 0 &&
                   total_len < length &&
                   total_len + block_size >= length ) );

    TEST_ASSERT( 0 == mbedtls_cipher_finish( &ctx_dec, decbuf + outlen, &outlen ) );
    total_len += outlen;

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_check_tag( &ctx_dec, tag, sizeof( tag ) ) );
#endif

    /* check result */
    TEST_ASSERT( total_len == length );
    TEST_ASSERT( 0 == memcmp(inbuf, decbuf, length) );
    }

    /*
     * Done
     */
exit:
    mbedtls_cipher_free( &ctx_dec );
    mbedtls_cipher_free( &ctx_enc );
}

void test_enc_dec_buf_wrapper( void ** params )
{

    test_enc_dec_buf( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 670 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_enc_fail( int cipher_id, int pad_mode, int key_len, int length_val,
               int ret )
{
    size_t length = length_val;
    unsigned char key[32];
    unsigned char iv[16];

    const mbedtls_cipher_info_t *cipher_info;
    mbedtls_cipher_context_t ctx;

    unsigned char inbuf[64];
    unsigned char encbuf[64];

    size_t outlen = 0;

    memset( key, 0, 32 );
    memset( iv , 0, 16 );

    mbedtls_cipher_init( &ctx );

    memset( inbuf, 5, 64 );
    memset( encbuf, 0, 64 );

    /* Check and get info structures */
    cipher_info = mbedtls_cipher_info_from_type( cipher_id );
    TEST_ASSERT( NULL != cipher_info );

    /* Initialise context */
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx, cipher_info ) );
    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx, key, key_len, MBEDTLS_ENCRYPT ) );
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx, pad_mode ) );
#else
    (void) pad_mode;
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx, iv, 16 ) );
    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx ) );
#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx, NULL, 0 ) );
#endif

    /* encode length number of bytes from inbuf */
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx, inbuf, length, encbuf, &outlen ) );
    TEST_ASSERT( ret == mbedtls_cipher_finish( &ctx, encbuf + outlen, &outlen ) );

    /* done */
exit:
    mbedtls_cipher_free( &ctx );
}

void test_enc_fail_wrapper( void ** params )
{

    test_enc_fail( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 722 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_dec_empty_buf( int cipher,
                    int expected_update_ret,
                    int expected_finish_ret )
{
    unsigned char key[32];
    unsigned char iv[16];

    mbedtls_cipher_context_t ctx_dec;
    const mbedtls_cipher_info_t *cipher_info;

    unsigned char encbuf[64];
    unsigned char decbuf[64];

    size_t outlen = 0;

    memset( key, 0, 32 );
    memset( iv , 0, 16 );

    mbedtls_cipher_init( &ctx_dec );

    memset( encbuf, 0, 64 );
    memset( decbuf, 0, 64 );

    /* Initialise context */
    cipher_info = mbedtls_cipher_info_from_type( cipher );
    TEST_ASSERT( NULL != cipher_info);
    TEST_ASSERT( sizeof(key) * 8 >= cipher_info->key_bitlen );

    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx_dec, cipher_info ) );

    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx_dec,
                                             key, cipher_info->key_bitlen,
                                             MBEDTLS_DECRYPT ) );

    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx_dec, iv, 16 ) );

    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx_dec ) );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx_dec, NULL, 0 ) );
#endif

    /* decode 0-byte string */
    TEST_ASSERT( expected_update_ret ==
                 mbedtls_cipher_update( &ctx_dec, encbuf, 0, decbuf, &outlen ) );
    TEST_ASSERT( 0 == outlen );

    if ( expected_finish_ret == 0 &&
         ( cipher_info->mode == MBEDTLS_MODE_CBC ||
           cipher_info->mode == MBEDTLS_MODE_ECB ) )
    {
        /* Non-CBC and non-ECB ciphers are OK with decrypting empty buffers and
         * return success, not MBEDTLS_ERR_CIPHER_FULL_BLOCK_EXPECTED, when
         * decrypting an empty buffer.
         * On the other hand, CBC and ECB ciphers need a full block of input.
         */
        expected_finish_ret = MBEDTLS_ERR_CIPHER_FULL_BLOCK_EXPECTED;
    }

    TEST_ASSERT( expected_finish_ret == mbedtls_cipher_finish(
                                        &ctx_dec, decbuf + outlen, &outlen ) );
    TEST_ASSERT( 0 == outlen );

exit:
    mbedtls_cipher_free( &ctx_dec );
}

void test_dec_empty_buf_wrapper( void ** params )
{

    test_dec_empty_buf( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 791 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_enc_dec_buf_multipart( int cipher_id, int key_len, int first_length_val,
                            int second_length_val, int pad_mode,
                            int first_encrypt_output_len, int second_encrypt_output_len,
                            int first_decrypt_output_len, int second_decrypt_output_len )
{
    size_t first_length = first_length_val;
    size_t second_length = second_length_val;
    size_t length = first_length + second_length;
    size_t block_size;
    unsigned char key[32];
    unsigned char iv[16];

    mbedtls_cipher_context_t ctx_dec;
    mbedtls_cipher_context_t ctx_enc;
    const mbedtls_cipher_info_t *cipher_info;

    unsigned char inbuf[64];
    unsigned char encbuf[64];
    unsigned char decbuf[64];

    size_t outlen = 0;
    size_t totaloutlen = 0;

    memset( key, 0, 32 );
    memset( iv , 0, 16 );

    mbedtls_cipher_init( &ctx_dec );
    mbedtls_cipher_init( &ctx_enc );

    memset( inbuf, 5, 64 );
    memset( encbuf, 0, 64 );
    memset( decbuf, 0, 64 );

    /* Initialise enc and dec contexts */
    cipher_info = mbedtls_cipher_info_from_type( cipher_id );
    TEST_ASSERT( NULL != cipher_info);

    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx_dec, cipher_info ) );
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx_enc, cipher_info ) );

    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx_dec, key, key_len, MBEDTLS_DECRYPT ) );
    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx_enc, key, key_len, MBEDTLS_ENCRYPT ) );

#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    if( -1 != pad_mode )
    {
        TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx_dec, pad_mode ) );
        TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx_enc, pad_mode ) );
    }
#else
    (void) pad_mode;
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */

    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx_dec, iv, 16 ) );
    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx_enc, iv, 16 ) );

    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx_dec ) );
    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx_enc ) );

#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx_dec, NULL, 0 ) );
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx_enc, NULL, 0 ) );
#endif

    block_size = mbedtls_cipher_get_block_size( &ctx_enc );
    TEST_ASSERT( block_size != 0 );

    /* encode length number of bytes from inbuf */
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx_enc, inbuf, first_length, encbuf, &outlen ) );
    TEST_ASSERT( (size_t)first_encrypt_output_len == outlen );
    totaloutlen = outlen;
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx_enc, inbuf + first_length, second_length, encbuf + totaloutlen, &outlen ) );
    TEST_ASSERT( (size_t)second_encrypt_output_len == outlen );
    totaloutlen += outlen;
    TEST_ASSERT( totaloutlen == length ||
                 ( totaloutlen % block_size == 0 &&
                   totaloutlen < length &&
                   totaloutlen + block_size > length ) );

    TEST_ASSERT( 0 == mbedtls_cipher_finish( &ctx_enc, encbuf + totaloutlen, &outlen ) );
    totaloutlen += outlen;
    TEST_ASSERT( totaloutlen == length ||
                 ( totaloutlen % block_size == 0 &&
                   totaloutlen > length &&
                   totaloutlen <= length + block_size ) );

    /* decode the previously encoded string */
    second_length = totaloutlen - first_length;
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx_dec, encbuf, first_length, decbuf, &outlen ) );
    TEST_ASSERT( (size_t)first_decrypt_output_len == outlen );
    totaloutlen = outlen;
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx_dec, encbuf + first_length, second_length, decbuf + totaloutlen, &outlen ) );
    TEST_ASSERT( (size_t)second_decrypt_output_len == outlen );
    totaloutlen += outlen;

    TEST_ASSERT( totaloutlen == length ||
                 ( totaloutlen % block_size == 0 &&
                   totaloutlen < length &&
                   totaloutlen + block_size >= length ) );

    TEST_ASSERT( 0 == mbedtls_cipher_finish( &ctx_dec, decbuf + totaloutlen, &outlen ) );
    totaloutlen += outlen;

    TEST_ASSERT( totaloutlen == length );

    TEST_ASSERT( 0 == memcmp(inbuf, decbuf, length) );

exit:
    mbedtls_cipher_free( &ctx_dec );
    mbedtls_cipher_free( &ctx_enc );
}

void test_enc_dec_buf_multipart_wrapper( void ** params )
{

    test_enc_dec_buf_multipart( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ), *( (int *) params[7] ), *( (int *) params[8] ) );
}
#line 905 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_decrypt_test_vec( int cipher_id, int pad_mode, data_t * key,
                       data_t * iv, data_t * cipher,
                       data_t * clear, data_t * ad, data_t * tag,
                       int finish_result, int tag_result )
{
    unsigned char output[265];
    mbedtls_cipher_context_t ctx;
    size_t outlen, total_len;

    mbedtls_cipher_init( &ctx );

    memset( output, 0x00, sizeof( output ) );

#if !defined(MBEDTLS_GCM_C) && !defined(MBEDTLS_CHACHAPOLY_C)
    ((void) ad);
    ((void) tag);
#endif

    /* Prepare context */
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx,
                                       mbedtls_cipher_info_from_type( cipher_id ) ) );
    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx, key->x, 8 * key->len, MBEDTLS_DECRYPT ) );
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    if( pad_mode != -1 )
        TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx, pad_mode ) );
#else
    (void) pad_mode;
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
    TEST_ASSERT( 0 == mbedtls_cipher_set_iv( &ctx, iv->x, iv->len ) );
    TEST_ASSERT( 0 == mbedtls_cipher_reset( &ctx ) );
#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( 0 == mbedtls_cipher_update_ad( &ctx, ad->x, ad->len ) );
#endif

    /* decode buffer and check tag->x */
    total_len = 0;
    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx, cipher->x, cipher->len, output, &outlen ) );
    total_len += outlen;
    TEST_ASSERT( finish_result == mbedtls_cipher_finish( &ctx, output + outlen,
                                                 &outlen ) );
    total_len += outlen;
#if defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CHACHAPOLY_C)
    TEST_ASSERT( tag_result == mbedtls_cipher_check_tag( &ctx, tag->x, tag->len ) );
#endif

    /* check plaintext only if everything went fine */
    if( 0 == finish_result && 0 == tag_result )
    {
        TEST_ASSERT( total_len == clear->len );
        TEST_ASSERT( 0 == memcmp( output, clear->x, clear->len ) );
    }

exit:
    mbedtls_cipher_free( &ctx );
}

void test_decrypt_test_vec_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};
    data_t data8 = {(uint8_t *) params[8], *( (uint32_t *) params[9] )};
    data_t data10 = {(uint8_t *) params[10], *( (uint32_t *) params[11] )};
    data_t data12 = {(uint8_t *) params[12], *( (uint32_t *) params[13] )};

    test_decrypt_test_vec( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, &data8, &data10, &data12, *( (int *) params[14] ), *( (int *) params[15] ) );
}
#if defined(MBEDTLS_CIPHER_MODE_AEAD)
#line 963 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_auth_crypt_tv( int cipher_id, data_t * key, data_t * iv,
                    data_t * ad, data_t * cipher, data_t * tag,
                    char * result, data_t * clear, int use_psa )
{
    /* Takes an AEAD ciphertext + tag and performs a pair
     * of AEAD decryption and AEAD encryption. It checks that
     * this results in the expected plaintext, and that
     * decryption and encryption are inverse to one another. */

    int ret;
    unsigned char output[300];        /* Temporary buffer for results of
                                       * encryption and decryption. */
    unsigned char *output_tag = NULL; /* Temporary buffer for tag in the
                                       * encryption step. */

    mbedtls_cipher_context_t ctx;
    size_t outlen;

    unsigned char *tmp_tag    = NULL;
    unsigned char *tmp_cipher = NULL;

    mbedtls_cipher_init( &ctx );
    memset( output, 0xFF, sizeof( output ) );

    /* Prepare context */
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
    (void) use_psa;
#else
    if( use_psa == 1 )
    {
        PSA_ASSERT( psa_crypto_init( ) );

        /* PSA requires that the tag immediately follows the ciphertext. */
        tmp_cipher = mbedtls_calloc( 1, cipher->len + tag->len );
        TEST_ASSERT( tmp_cipher != NULL );
        tmp_tag = tmp_cipher + cipher->len;

        memcpy( tmp_cipher, cipher->x, cipher->len );
        memcpy( tmp_tag, tag->x, tag->len );

        TEST_ASSERT( 0 == mbedtls_cipher_setup_psa( &ctx,
                              mbedtls_cipher_info_from_type( cipher_id ),
                              tag->len ) );
    }
    else
#endif
    {
        tmp_tag = tag->x;
        tmp_cipher = cipher->x;
        TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx,
                              mbedtls_cipher_info_from_type( cipher_id ) ) );
    }

    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx, key->x, 8 * key->len,
                                             MBEDTLS_DECRYPT ) );

    /* decode buffer and check tag->x */

    /* Sanity check that we don't use overly long inputs. */
    TEST_ASSERT( sizeof( output ) >= cipher->len );

    ret = mbedtls_cipher_auth_decrypt( &ctx, iv->x, iv->len, ad->x, ad->len,
                               tmp_cipher, cipher->len, output, &outlen,
                               tmp_tag, tag->len );

    /* make sure the message is rejected if it should be */
    if( strcmp( result, "FAIL" ) == 0 )
    {
        TEST_ASSERT( ret == MBEDTLS_ERR_CIPHER_AUTH_FAILED );
        goto exit;
    }

    /* otherwise, make sure it was decrypted properly */
    TEST_ASSERT( ret == 0 );

    TEST_ASSERT( outlen == clear->len );
    TEST_ASSERT( memcmp( output, clear->x, clear->len ) == 0 );

    /* then encrypt the clear->x and make sure we get the same ciphertext and tag->x */
    mbedtls_cipher_free( &ctx );
#if defined(MBEDTLS_USE_PSA_CRYPTO)
    if( use_psa == 1 )
    {
        TEST_ASSERT( 0 == mbedtls_cipher_setup_psa( &ctx,
                              mbedtls_cipher_info_from_type( cipher_id ),
                              tag->len ) );
    }
    else
#endif
    {
        TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx,
                              mbedtls_cipher_info_from_type( cipher_id ) ) );
    }
    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx, key->x, 8 * key->len,
                                             MBEDTLS_ENCRYPT ) );

    memset( output, 0xFF, sizeof( output ) );
    outlen = 0;

    /* Sanity check that we don't use overly long inputs. */
    TEST_ASSERT( sizeof( output ) >= clear->len + tag->len );

    output_tag = output + clear->len;
    ret = mbedtls_cipher_auth_encrypt( &ctx, iv->x, iv->len, ad->x, ad->len,
                               clear->x, clear->len, output, &outlen,
                               output_tag, tag->len );
    TEST_ASSERT( ret == 0 );

    TEST_ASSERT( outlen == cipher->len );
    TEST_ASSERT( memcmp( output, cipher->x, cipher->len ) == 0 );
    TEST_ASSERT( memcmp( output_tag, tag->x, tag->len ) == 0 );

exit:

    mbedtls_cipher_free( &ctx );

#if defined(MBEDTLS_USE_PSA_CRYPTO)
    if( use_psa == 1 )
    {
        mbedtls_free( tmp_cipher );
        PSA_DONE( );
    }
#endif /* MBEDTLS_USE_PSA_CRYPTO */
}

void test_auth_crypt_tv_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data5 = {(uint8_t *) params[5], *( (uint32_t *) params[6] )};
    data_t data7 = {(uint8_t *) params[7], *( (uint32_t *) params[8] )};
    data_t data9 = {(uint8_t *) params[9], *( (uint32_t *) params[10] )};
    data_t data12 = {(uint8_t *) params[12], *( (uint32_t *) params[13] )};

    test_auth_crypt_tv( *( (int *) params[0] ), &data1, &data3, &data5, &data7, &data9, (char *) params[11], &data12, *( (int *) params[14] ) );
}
#endif /* MBEDTLS_CIPHER_MODE_AEAD */
#line 1090 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_test_vec_ecb( int cipher_id, int operation, data_t * key,
                   data_t * input, data_t * result, int finish_result
                   )
{
    mbedtls_cipher_context_t ctx;
    unsigned char output[32];
    size_t outlen;

    mbedtls_cipher_init( &ctx );

    memset( output, 0x00, sizeof( output ) );

    /* Prepare context */
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx,
                                       mbedtls_cipher_info_from_type( cipher_id ) ) );


    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx, key->x, 8 * key->len, operation ) );

    TEST_ASSERT( 0 == mbedtls_cipher_update( &ctx, input->x,
                                     mbedtls_cipher_get_block_size( &ctx ),
                                     output, &outlen ) );
    TEST_ASSERT( outlen == mbedtls_cipher_get_block_size( &ctx ) );
    TEST_ASSERT( finish_result == mbedtls_cipher_finish( &ctx, output + outlen,
                                                 &outlen ) );
    TEST_ASSERT( 0 == outlen );

    /* check plaintext only if everything went fine */
    if( 0 == finish_result )
        TEST_ASSERT( 0 == memcmp( output, result->x,
                                  mbedtls_cipher_get_block_size( &ctx ) ) );

exit:
    mbedtls_cipher_free( &ctx );
}

void test_test_vec_ecb_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_test_vec_ecb( *( (int *) params[0] ), *( (int *) params[1] ), &data2, &data4, &data6, *( (int *) params[8] ) );
}
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
#line 1128 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_test_vec_crypt( int cipher_id, int operation, char *hex_key,
                     char *hex_iv, char *hex_input, char *hex_result,
                     int finish_result, int use_psa )
{
    unsigned char key[50];
    unsigned char input[16];
    unsigned char result[16];
    unsigned char iv[16];
    size_t key_len, iv_len, inputlen, resultlen;
    mbedtls_cipher_context_t ctx;
    unsigned char output[32];
    size_t outlen;

    mbedtls_cipher_init( &ctx );

    memset( key, 0x00, sizeof( key ) );
    memset( input, 0x00, sizeof( input ) );
    memset( result, 0x00, sizeof( result ) );
    memset( output, 0x00, sizeof( output ) );
    memset( iv, 0x00, sizeof( iv ) );

    /* Prepare context */
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
    (void) use_psa;
#else
    if( use_psa == 1 )
    {
        PSA_ASSERT( psa_crypto_init( ) );
        TEST_ASSERT( 0 == mbedtls_cipher_setup_psa( &ctx,
                              mbedtls_cipher_info_from_type( cipher_id ), 0 ) );
    }
    else
#endif /* MBEDTLS_USE_PSA_CRYPTO */
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx,
                              mbedtls_cipher_info_from_type( cipher_id ) ) );

    key_len = unhexify( key, hex_key );
    inputlen =  unhexify( input, hex_input );
    resultlen = unhexify( result, hex_result );

    TEST_ASSERT( 0 == mbedtls_cipher_setkey( &ctx, key, 8 * key_len, operation ) );
    if( MBEDTLS_MODE_CBC == ctx.cipher_info->mode )
        TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx, MBEDTLS_PADDING_NONE ) );

    iv_len = unhexify( iv, hex_iv );

    TEST_ASSERT( finish_result == mbedtls_cipher_crypt( &ctx, iv_len ? iv : NULL,
                                                        iv_len, input, inputlen,
                                                        output, &outlen ) );
    TEST_ASSERT( resultlen == outlen );
    /* check plaintext only if everything went fine */
    if( 0 == finish_result )
        TEST_ASSERT( 0 == memcmp( output, result, outlen ) );

exit:
    mbedtls_cipher_free( &ctx );
#if defined(MBEDTLS_USE_PSA_CRYPTO)
    PSA_DONE( );
#endif /* MBEDTLS_USE_PSA_CRYPTO */
}

void test_test_vec_crypt_wrapper( void ** params )
{

    test_test_vec_crypt( *( (int *) params[0] ), *( (int *) params[1] ), (char *) params[2], (char *) params[3], (char *) params[4], (char *) params[5], *( (int *) params[6] ), *( (int *) params[7] ) );
}
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
#if defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
#line 1191 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_set_padding( int cipher_id, int pad_mode, int ret )
{
    const mbedtls_cipher_info_t *cipher_info;
    mbedtls_cipher_context_t ctx;

    mbedtls_cipher_init( &ctx );

    cipher_info = mbedtls_cipher_info_from_type( cipher_id );
    TEST_ASSERT( NULL != cipher_info );
    TEST_ASSERT( 0 == mbedtls_cipher_setup( &ctx, cipher_info ) );

    TEST_ASSERT( ret == mbedtls_cipher_set_padding_mode( &ctx, pad_mode ) );

exit:
    mbedtls_cipher_free( &ctx );
}

void test_set_padding_wrapper( void ** params )
{

    test_set_padding( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* MBEDTLS_CIPHER_MODE_WITH_PADDING */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#line 1210 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function"
void test_check_padding( int pad_mode, data_t * input, int ret, int dlen_check
                    )
{
    mbedtls_cipher_info_t cipher_info;
    mbedtls_cipher_context_t ctx;
    size_t dlen;

    /* build a fake context just for getting access to get_padding */
    mbedtls_cipher_init( &ctx );
    cipher_info.mode = MBEDTLS_MODE_CBC;
    ctx.cipher_info = &cipher_info;

    TEST_ASSERT( 0 == mbedtls_cipher_set_padding_mode( &ctx, pad_mode ) );


    TEST_ASSERT( ret == ctx.get_padding( input->x, input->len, &dlen ) );
    if( 0 == ret )
        TEST_ASSERT( dlen == (size_t) dlen_check );
exit:
    ;
}

void test_check_padding_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};

    test_check_padding( *( (int *) params[0] ), &data1, *( (int *) params[3] ), *( (int *) params[4] ) );
}
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_CIPHER_C */


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

#if defined(MBEDTLS_CIPHER_C)

        case 0:
            {
                *out_value = MBEDTLS_CIPHER_ARC4_128;
            }
            break;
        case 1:
            {
                *out_value = -1;
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

#if defined(MBEDTLS_CIPHER_C)

        case 0:
            {
#if defined(MBEDTLS_ARC4_C)
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

#if defined(MBEDTLS_CIPHER_C)
    test_mbedtls_cipher_list_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_CIPHER_C)
    test_cipher_invalid_param_unconditional_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_CHECK_PARAMS) && !defined(MBEDTLS_PARAM_FAILED_ALT)
    test_cipher_invalid_param_conditional_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_AES_C)
    test_cipher_special_behaviours_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_CIPHER_C)
    test_enc_dec_buf_wrapper,
#else
    NULL,
#endif
/* Function Id: 5 */

#if defined(MBEDTLS_CIPHER_C)
    test_enc_fail_wrapper,
#else
    NULL,
#endif
/* Function Id: 6 */

#if defined(MBEDTLS_CIPHER_C)
    test_dec_empty_buf_wrapper,
#else
    NULL,
#endif
/* Function Id: 7 */

#if defined(MBEDTLS_CIPHER_C)
    test_enc_dec_buf_multipart_wrapper,
#else
    NULL,
#endif
/* Function Id: 8 */

#if defined(MBEDTLS_CIPHER_C)
    test_decrypt_test_vec_wrapper,
#else
    NULL,
#endif
/* Function Id: 9 */

#if defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_CIPHER_MODE_AEAD)
    test_auth_crypt_tv_wrapper,
#else
    NULL,
#endif
/* Function Id: 10 */

#if defined(MBEDTLS_CIPHER_C)
    test_test_vec_ecb_wrapper,
#else
    NULL,
#endif
/* Function Id: 11 */

#if defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    test_test_vec_crypt_wrapper,
#else
    NULL,
#endif
/* Function Id: 12 */

#if defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_CIPHER_MODE_WITH_PADDING)
    test_set_padding_wrapper,
#else
    NULL,
#endif
/* Function Id: 13 */

#if defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_CIPHER_MODE_CBC)
    test_check_padding_wrapper,
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
    const char *default_filename = "./test_suite_cipher.arc4.datax";
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
