#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_psa_crypto_se_driver_hal.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/main_test.function
 *      Platform code file  : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/host_test.function
 *      Helper file         : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/helpers.function
 *      Test suite file     : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function
 *      Test suite data     : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.data
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

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
#line 2 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
#include "psa_crypto_helpers.h"
#include "psa/crypto_se_driver.h"

#include "psa_crypto_se.h"
#include "psa_crypto_storage.h"

/* Invasive peeking: check the persistent data */
#if defined(MBEDTLS_PSA_ITS_FILE_C)
#include "psa_crypto_its.h"
#else /* Native ITS implementation */
#include "psa/error.h"
#include "psa/internal_trusted_storage.h"
#endif


/****************************************************************/
/* Test driver helpers */
/****************************************************************/

/** The minimum valid lifetime value for a secure element driver. */
#define MIN_DRIVER_LIFETIME 2

/** The driver detected a condition that shouldn't happen.
 * This is probably a bug in the library. */
#define PSA_ERROR_DETECTED_BY_DRIVER ((psa_status_t)( -500 ))

/** Like #TEST_ASSERT for use in a driver method, with no cleanup.
 *
 * If an error happens, this macro returns from the calling function.
 *
 * Use this macro to assert on guarantees provided by the core.
 */
#define DRIVER_ASSERT_RETURN( TEST )                        \
    do {                                                    \
       if( ! (TEST) )                                       \
       {                                                    \
          test_fail( #TEST, __LINE__, __FILE__ );           \
          return( PSA_ERROR_DETECTED_BY_DRIVER );           \
       }                                                    \
    } while( 0 )

/** Like #TEST_ASSERT for use in a driver method, with cleanup.
 *
 * In case of error, this macro sets `status` and jumps to the
 * label `exit`.
 *
 * Use this macro to assert on guarantees provided by the core.
 */
#define DRIVER_ASSERT( TEST )                               \
    do {                                                    \
       if( ! (TEST) )                                       \
       {                                                    \
          test_fail( #TEST, __LINE__, __FILE__ );           \
          status = PSA_ERROR_DETECTED_BY_DRIVER;            \
          goto exit;                                        \
       }                                                    \
    } while( 0 )

/** Like #PSA_ASSERT for a PSA API call that calls a driver underneath.
 *
 * Run the code \p expr. If this returns \p expected_status,
 * do nothing. If this returns #PSA_ERROR_DETECTED_BY_DRIVER,
 * jump directly to the `exit` label. If this returns any other
 * status, call test_fail() then jump to `exit`.
 *
 * The special case for #PSA_ERROR_DETECTED_BY_DRIVER is because in this
 * case, the test driver code is expected to have called test_fail()
 * already, so we make sure not to overwrite the failure information.
 */
#define PSA_ASSERT_VIA_DRIVER( expr, expected_status )                  \
    do {                                                                \
        psa_status_t PSA_ASSERT_VIA_DRIVER_status = ( expr );           \
        if( PSA_ASSERT_VIA_DRIVER_status == PSA_ERROR_DETECTED_BY_DRIVER ) \
            goto exit;                                                  \
        if( PSA_ASSERT_VIA_DRIVER_status != ( expected_status ) )       \
        {                                                               \
            test_fail( #expr, __LINE__, __FILE__ );                     \
            goto exit;                                                  \
        }                                                               \
    } while( 0 )



/****************************************************************/
/* Domain support functions */
/****************************************************************/

/* Return the exact bit size given a curve family and a byte length. */
static size_t ecc_curve_bits( psa_ecc_curve_t curve, size_t data_length )
{
    switch( curve )
    {
        case PSA_ECC_CURVE_SECP_R1:
            if( data_length == PSA_BYTES_TO_BITS( 521 ) )
                return( 521 );
            break;
        case PSA_ECC_CURVE_MONTGOMERY:
            if( data_length == PSA_BYTES_TO_BITS( 255 ) )
                return( 255 );
    }
    /* If not listed above, assume a multiple of 8 bits. */
    return( PSA_BYTES_TO_BITS( data_length ) );
}


/****************************************************************/
/* Miscellaneous driver methods */
/****************************************************************/

typedef struct
{
    psa_key_slot_number_t slot_number;
    psa_key_creation_method_t method;
    psa_status_t status;
} validate_slot_number_directions_t;
static validate_slot_number_directions_t validate_slot_number_directions;

/* Validate a choice of slot number as directed. */
static psa_status_t validate_slot_number_as_directed(
    psa_drv_se_context_t *context,
    void *persistent_data,
    const psa_key_attributes_t *attributes,
    psa_key_creation_method_t method,
    psa_key_slot_number_t slot_number )
{
    (void) context;
    (void) persistent_data;
    (void) attributes;
    DRIVER_ASSERT_RETURN( slot_number ==
                          validate_slot_number_directions.slot_number );
    DRIVER_ASSERT_RETURN( method ==
                          validate_slot_number_directions.method );
    return( validate_slot_number_directions.status );
}

/* Allocate slot numbers with a monotonic counter. */
static psa_key_slot_number_t shadow_counter;
static void counter_reset( void )
{
    shadow_counter = 0;
}
static psa_status_t counter_allocate( psa_drv_se_context_t *context,
                                      void *persistent_data,
                                      const psa_key_attributes_t *attributes,
                                      psa_key_creation_method_t method,
                                      psa_key_slot_number_t *slot_number )
{
    psa_key_slot_number_t *p_counter = persistent_data;
    (void) attributes;
    (void) method;
    if( context->persistent_data_size != sizeof( psa_key_slot_number_t ) )
        return( PSA_ERROR_DETECTED_BY_DRIVER );
    ++*p_counter;
    if( *p_counter == 0 )
        return( PSA_ERROR_INSUFFICIENT_STORAGE );
    shadow_counter = *p_counter;
    *slot_number = *p_counter;
    return( PSA_SUCCESS );
}

/* Null import: do nothing, but pretend it worked. */
static psa_status_t null_import( psa_drv_se_context_t *context,
                                 psa_key_slot_number_t slot_number,
                                 const psa_key_attributes_t *attributes,
                                 const uint8_t *data,
                                 size_t data_length,
                                 size_t *bits )
{
    (void) context;
    (void) slot_number;
    (void) attributes;
    (void) data;
    /* We're supposed to return a key size. Return one that's correct for
     * plain data keys. */
    *bits = PSA_BYTES_TO_BITS( data_length );
    return( PSA_SUCCESS );
}

/* Null generate: do nothing, but pretend it worked. */
static psa_status_t null_generate( psa_drv_se_context_t *context,
                                   psa_key_slot_number_t slot_number,
                                   const psa_key_attributes_t *attributes,
                                   uint8_t *pubkey,
                                   size_t pubkey_size,
                                   size_t *pubkey_length )
{
    (void) context;
    (void) slot_number;
    (void) attributes;

    DRIVER_ASSERT_RETURN( *pubkey_length == 0 );
    if( ! PSA_KEY_TYPE_IS_KEY_PAIR( psa_get_key_type( attributes ) ) )
    {
        DRIVER_ASSERT_RETURN( pubkey == NULL );
        DRIVER_ASSERT_RETURN( pubkey_size == 0 );
    }

    return( PSA_SUCCESS );
}

/* Null destroy: do nothing, but pretend it worked. */
static psa_status_t null_destroy( psa_drv_se_context_t *context,
                                  void *persistent_data,
                                  psa_key_slot_number_t slot_number )
{
    (void) context;
    (void) persistent_data;
    (void) slot_number;
    return( PSA_SUCCESS );
}



/****************************************************************/
/* RAM-based test driver */
/****************************************************************/

#define RAM_MAX_KEY_SIZE 64
typedef struct
{
    psa_key_lifetime_t lifetime;
    psa_key_type_t type;
    size_t bits;
    uint8_t content[RAM_MAX_KEY_SIZE];
} ram_slot_t;
static ram_slot_t ram_slots[16];

/* A type with at least ARRAY_LENGTH(ram_slots) bits, containing a
 * bit vector indicating which slots are in use. */
typedef uint16_t ram_slot_usage_t;

static ram_slot_usage_t ram_shadow_slot_usage;

static uint8_t ram_min_slot = 0;

static void ram_slots_reset( void )
{
    memset( ram_slots, 0, sizeof( ram_slots ) );
    ram_min_slot = 0;
    ram_shadow_slot_usage = 0;
}

/* Common parts of key creation.
 *
 * In case of error, zero out ram_slots[slot_number]. But don't
 * do that if the error is PSA_ERROR_DETECTED_BY_DRIVER: in this case
 * you don't need to clean up (ram_slot_reset() will take care of it
 * in the test case function's cleanup code) and it might be wrong
 * (if slot_number is invalid).
 */
static psa_status_t ram_create_common( psa_drv_se_context_t *context,
                                       psa_key_slot_number_t slot_number,
                                       const psa_key_attributes_t *attributes,
                                       size_t required_storage )
{
    (void) context;
    DRIVER_ASSERT_RETURN( slot_number < ARRAY_LENGTH( ram_slots ) );

    ram_slots[slot_number].lifetime = psa_get_key_lifetime( attributes );
    ram_slots[slot_number].type = psa_get_key_type( attributes );
    ram_slots[slot_number].bits = psa_get_key_bits( attributes );

    if( required_storage > sizeof( ram_slots[slot_number].content ) )
    {
        memset( &ram_slots[slot_number], 0, sizeof( ram_slots[slot_number] ) );
        return( PSA_ERROR_INSUFFICIENT_STORAGE );
    }

    return( PSA_SUCCESS );
}

/* This function does everything except actually generating key material.
 * After calling it, you must copy the desired key material to
 * ram_slots[slot_number].content. */
static psa_status_t ram_fake_generate( psa_drv_se_context_t *context,
                                       psa_key_slot_number_t slot_number,
                                       const psa_key_attributes_t *attributes,
                                       uint8_t *pubkey,
                                       size_t pubkey_size,
                                       size_t *pubkey_length )
{
    psa_status_t status;
    size_t required_storage =
        PSA_KEY_EXPORT_MAX_SIZE( psa_get_key_type( attributes ),
                                 psa_get_key_bits( attributes ) );

    DRIVER_ASSERT_RETURN( *pubkey_length == 0 );
    if( ! PSA_KEY_TYPE_IS_KEY_PAIR( psa_get_key_type( attributes ) ) )
    {
        DRIVER_ASSERT_RETURN( pubkey == NULL );
        DRIVER_ASSERT_RETURN( pubkey_size == 0 );
    }

    status = ram_create_common( context, slot_number, attributes,
                                required_storage );
    return( status );
}

static psa_status_t ram_import( psa_drv_se_context_t *context,
                                psa_key_slot_number_t slot_number,
                                const psa_key_attributes_t *attributes,
                                const uint8_t *data,
                                size_t data_length,
                                size_t *bits )
{
    psa_key_type_t type = psa_get_key_type( attributes );
    psa_status_t status = ram_create_common( context, slot_number, attributes,
                                             data_length );
    if( status != PSA_SUCCESS )
        return( status );

    /* The RAM driver only works for certain key types: raw keys,
     * and ECC key pairs. This is true in particular of the bit-size
     * calculation here. */
    if( PSA_KEY_TYPE_IS_UNSTRUCTURED( type ) )
        *bits = PSA_BYTES_TO_BITS( data_length );
    else if ( PSA_KEY_TYPE_IS_ECC_KEY_PAIR( type ) )
    {
        *bits = ecc_curve_bits( PSA_KEY_TYPE_GET_CURVE( type ), data_length );
        if( *bits == 0 )
            return( PSA_ERROR_DETECTED_BY_DRIVER );
    }
    else
    {
        memset( &ram_slots[slot_number], 0, sizeof( ram_slots[slot_number] ) );
        return( PSA_ERROR_NOT_SUPPORTED );
    }

    ram_slots[slot_number].bits = *bits;
    memcpy( ram_slots[slot_number].content, data, data_length );

    return( PSA_SUCCESS );
}

static psa_status_t ram_export( psa_drv_se_context_t *context,
                                psa_key_slot_number_t slot_number,
                                uint8_t *data,
                                size_t data_size,
                                size_t *data_length )
{
    size_t actual_size;
    (void) context;
    DRIVER_ASSERT_RETURN( slot_number < ARRAY_LENGTH( ram_slots ) );
    actual_size = PSA_BITS_TO_BYTES( ram_slots[slot_number].bits );
    if( actual_size > data_size )
        return( PSA_ERROR_BUFFER_TOO_SMALL );
    *data_length = actual_size;
    memcpy( data, ram_slots[slot_number].content, actual_size );
    return( PSA_SUCCESS );
}

static psa_status_t ram_export_public( psa_drv_se_context_t *context,
                                       psa_key_slot_number_t slot_number,
                                       uint8_t *data,
                                       size_t data_size,
                                       size_t *data_length )
{
    psa_status_t status;
    psa_key_handle_t handle;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    (void) context;
    DRIVER_ASSERT_RETURN( slot_number < ARRAY_LENGTH( ram_slots ) );
    DRIVER_ASSERT_RETURN(
        PSA_KEY_TYPE_IS_KEY_PAIR( ram_slots[slot_number].type ) );

    psa_set_key_type( &attributes, ram_slots[slot_number].type );
    status = psa_import_key( &attributes,
                             ram_slots[slot_number].content,
                             PSA_BITS_TO_BYTES( ram_slots[slot_number].bits ),
                             &handle );
    if( status != PSA_SUCCESS )
        return( status );
    status = psa_export_public_key( handle, data, data_size, data_length );
    psa_destroy_key( handle );
    return( PSA_SUCCESS );
}

static psa_status_t ram_destroy( psa_drv_se_context_t *context,
                                 void *persistent_data,
                                 psa_key_slot_number_t slot_number )
{
    ram_slot_usage_t *slot_usage = persistent_data;
    DRIVER_ASSERT_RETURN( context->persistent_data_size == sizeof( ram_slot_usage_t ) );
    DRIVER_ASSERT_RETURN( slot_number < ARRAY_LENGTH( ram_slots ) );
    memset( &ram_slots[slot_number], 0, sizeof( ram_slots[slot_number] ) );
    *slot_usage &= ~(ram_slot_usage_t)( 1 << slot_number );
    ram_shadow_slot_usage = *slot_usage;
    return( PSA_SUCCESS );
}

static psa_status_t ram_allocate( psa_drv_se_context_t *context,
                                  void *persistent_data,
                                  const psa_key_attributes_t *attributes,
                                  psa_key_creation_method_t method,
                                  psa_key_slot_number_t *slot_number )
{
    ram_slot_usage_t *slot_usage = persistent_data;
    (void) attributes;
    (void) method;
    DRIVER_ASSERT_RETURN( context->persistent_data_size == sizeof( ram_slot_usage_t ) );
    for( *slot_number = ram_min_slot;
         *slot_number < ARRAY_LENGTH( ram_slots );
         ++( *slot_number ) )
    {
        if( ! ( *slot_usage & 1 << *slot_number ) )
        {
            ram_shadow_slot_usage = *slot_usage;
            return( PSA_SUCCESS );
        }
    }
    return( PSA_ERROR_INSUFFICIENT_STORAGE );
}

static psa_status_t ram_validate_slot_number(
    psa_drv_se_context_t *context,
    void *persistent_data,
    const psa_key_attributes_t *attributes,
    psa_key_creation_method_t method,
    psa_key_slot_number_t slot_number )
{
    (void) context;
    (void) persistent_data;
    (void) attributes;
    (void) method;
    if( slot_number >= ARRAY_LENGTH( ram_slots ) )
        return( PSA_ERROR_INVALID_ARGUMENT );
    return( PSA_SUCCESS );
}

static psa_status_t ram_sign( psa_drv_se_context_t *context,
                              psa_key_slot_number_t slot_number,
                              psa_algorithm_t alg,
                              const uint8_t *hash,
                              size_t hash_length,
                              uint8_t *signature,
                              size_t signature_size,
                              size_t *signature_length )
{
    ram_slot_t *slot;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t handle = 0;
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;

    (void) context;
    DRIVER_ASSERT_RETURN( slot_number < ARRAY_LENGTH( ram_slots ) );
    slot = &ram_slots[slot_number];

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_SIGN_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, slot->type );
    DRIVER_ASSERT( psa_import_key( &attributes,
                                   slot->content,
                                   PSA_BITS_TO_BYTES( slot->bits ),
                                   &handle ) == PSA_SUCCESS );
    status = psa_sign_hash( handle, alg,
                            hash, hash_length,
                            signature, signature_size, signature_length );

exit:
    psa_destroy_key( handle );
    return( status );
}

static psa_status_t ram_verify( psa_drv_se_context_t *context,
                                psa_key_slot_number_t slot_number,
                                psa_algorithm_t alg,
                                const uint8_t *hash,
                                size_t hash_length,
                                const uint8_t *signature,
                                size_t signature_length )
{
    ram_slot_t *slot;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_handle_t handle = 0;
    psa_status_t status = PSA_ERROR_GENERIC_ERROR;

    (void) context;
    DRIVER_ASSERT_RETURN( slot_number < ARRAY_LENGTH( ram_slots ) );
    slot = &ram_slots[slot_number];

    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, slot->type );
    DRIVER_ASSERT( psa_import_key( &attributes,
                                   slot->content,
                                   PSA_BITS_TO_BYTES( slot->bits ),
                                   &handle ) ==
                   PSA_SUCCESS );
    status = psa_verify_hash( handle, alg,
                              hash, hash_length,
                              signature, signature_length );

exit:
    psa_destroy_key( handle );
    return( status );
}




/****************************************************************/
/* Other test helper functions */
/****************************************************************/

typedef enum
{
    SIGN_IN_SOFTWARE_AND_PARALLEL_CREATION,
    SIGN_IN_DRIVER_AND_PARALLEL_CREATION,
    SIGN_IN_DRIVER_THEN_EXPORT_PUBLIC,
} sign_verify_method_t;

/* Check that the attributes of a key reported by psa_get_key_attributes()
 * are consistent with the attributes used when creating the key. */
static int check_key_attributes(
    psa_key_handle_t handle,
    const psa_key_attributes_t *reference_attributes )
{
    int ok = 0;
    psa_key_attributes_t actual_attributes = PSA_KEY_ATTRIBUTES_INIT;

    PSA_ASSERT( psa_get_key_attributes( handle, &actual_attributes ) );

    TEST_EQUAL( psa_get_key_id( &actual_attributes ),
                psa_get_key_id( reference_attributes ) );
    TEST_EQUAL( psa_get_key_lifetime( &actual_attributes ),
                psa_get_key_lifetime( reference_attributes ) );
    TEST_EQUAL( psa_get_key_type( &actual_attributes ),
                psa_get_key_type( reference_attributes ) );
    TEST_EQUAL( psa_get_key_usage_flags( &actual_attributes ),
                psa_get_key_usage_flags( reference_attributes ) );
    TEST_EQUAL( psa_get_key_algorithm( &actual_attributes ),
                psa_get_key_algorithm( reference_attributes ) );
    TEST_EQUAL( psa_get_key_enrollment_algorithm( &actual_attributes ),
                psa_get_key_enrollment_algorithm( reference_attributes ) );
    if( psa_get_key_bits( reference_attributes ) != 0 )
    {
        TEST_EQUAL( psa_get_key_bits( &actual_attributes ),
                    psa_get_key_bits( reference_attributes ) );
    }

    {
        psa_key_slot_number_t actual_slot_number = 0xdeadbeef;
        psa_key_slot_number_t desired_slot_number = 0xb90cc011;
        psa_key_lifetime_t lifetime =
            psa_get_key_lifetime( &actual_attributes );
        psa_status_t status = psa_get_key_slot_number( &actual_attributes,
                                                       &actual_slot_number );
        if( lifetime < MIN_DRIVER_LIFETIME )
        {
            /* The key is not in a secure element. */
            TEST_EQUAL( status, PSA_ERROR_INVALID_ARGUMENT );
        }
        else
        {
            /* The key is in a secure element. If it had been created
             * in a specific slot, check that it is reported there. */
            PSA_ASSERT( status );
            status = psa_get_key_slot_number( reference_attributes,
                                              &desired_slot_number );
            if( status == PSA_SUCCESS )
            {
                TEST_EQUAL( desired_slot_number, actual_slot_number );
            }
        }
    }
    ok = 1;

exit:
    return( ok );
}

/* Get the file UID corresponding to the specified lifetime.
 * If this changes, the storage format version must change.
 * See psa_get_se_driver_its_file_uid() in psa_crypto_se.c.
 */
psa_storage_uid_t file_uid_for_lifetime( psa_key_lifetime_t lifetime )
{
    if( lifetime > PSA_MAX_SE_LIFETIME )
        return( 0 );
    return( 0xfffffe00 + lifetime );
}

/* Check that the persistent data of a driver has its expected content. */
static int check_persistent_data( psa_key_lifetime_t lifetime,
                                  const void *expected_data,
                                  size_t size )
{
    psa_storage_uid_t uid = file_uid_for_lifetime( lifetime );
    struct psa_storage_info_t info;
    uint8_t *loaded = NULL;
    int ok = 0;

    PSA_ASSERT( psa_its_get_info( uid, &info ) );
    ASSERT_ALLOC( loaded, info.size );
    PSA_ASSERT( psa_its_get( uid, 0, info.size, loaded, NULL ) );
    ASSERT_COMPARE( expected_data, size, loaded, info.size );
    ok = 1;

exit:
    mbedtls_free( loaded );
    return( ok );
}

/* Check that a function's return status is "smoke-free", i.e. that
 * it's an acceptable error code when calling an API function that operates
 * on a key with potentially bogus parameters. */
static int is_status_smoke_free( psa_status_t status )
{
    switch( status )
    {
        case PSA_SUCCESS:
        case PSA_ERROR_NOT_SUPPORTED:
        case PSA_ERROR_NOT_PERMITTED:
        case PSA_ERROR_BUFFER_TOO_SMALL:
        case PSA_ERROR_INVALID_ARGUMENT:
        case PSA_ERROR_INVALID_SIGNATURE:
        case PSA_ERROR_INVALID_PADDING:
            return( 1 );
        default:
            return( 0 );
    }
}
#define SMOKE_ASSERT( expr )                    \
    TEST_ASSERT( is_status_smoke_free( expr ) )

/* Smoke test a key. There are mostly no wrong answers here since we pass
 * mostly bogus parameters: the goal is to ensure that there is no memory
 * corruption or crash. This test function is most useful when run under
 * an environment with sanity checks such as ASan or MSan. */
static int smoke_test_key( psa_key_handle_t handle )
{
    int ok = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_mac_operation_t mac_operation = PSA_MAC_OPERATION_INIT;
    psa_cipher_operation_t cipher_operation = PSA_CIPHER_OPERATION_INIT;
    psa_key_derivation_operation_t derivation_operation =
        PSA_KEY_DERIVATION_OPERATION_INIT;
    uint8_t buffer[80]; /* large enough for a public key for ECDH */
    size_t length;
    psa_key_handle_t handle2 = 0;

    SMOKE_ASSERT( psa_get_key_attributes( handle, &attributes ) );

    SMOKE_ASSERT( psa_export_key( handle,
                                  buffer, sizeof( buffer ), &length ) );
    SMOKE_ASSERT( psa_export_public_key( handle,
                                         buffer, sizeof( buffer ), &length ) );

    SMOKE_ASSERT( psa_copy_key( handle, &attributes, &handle2 ) );
    if( handle2 != 0 )
        PSA_ASSERT( psa_close_key( handle2 ) );

    SMOKE_ASSERT( psa_mac_sign_setup( &mac_operation, handle, PSA_ALG_CMAC ) );
    PSA_ASSERT( psa_mac_abort( &mac_operation ) );
    SMOKE_ASSERT( psa_mac_verify_setup( &mac_operation, handle,
                                        PSA_ALG_HMAC( PSA_ALG_SHA_256 ) ) );
    PSA_ASSERT( psa_mac_abort( &mac_operation ) );

    SMOKE_ASSERT( psa_cipher_encrypt_setup( &cipher_operation, handle,
                                            PSA_ALG_CTR ) );
    PSA_ASSERT( psa_cipher_abort( &cipher_operation ) );
    SMOKE_ASSERT( psa_cipher_decrypt_setup( &cipher_operation, handle,
                                            PSA_ALG_CTR ) );
    PSA_ASSERT( psa_cipher_abort( &cipher_operation ) );

    SMOKE_ASSERT( psa_aead_encrypt( handle, PSA_ALG_CCM,
                                    buffer, sizeof( buffer ),
                                    NULL, 0,
                                    buffer, sizeof( buffer),
                                    buffer, sizeof( buffer), &length ) );
    SMOKE_ASSERT( psa_aead_decrypt( handle, PSA_ALG_CCM,
                                    buffer, sizeof( buffer ),
                                    NULL, 0,
                                    buffer, sizeof( buffer),
                                    buffer, sizeof( buffer), &length ) );

    SMOKE_ASSERT( psa_sign_hash( handle, PSA_ALG_ECDSA_ANY,
                                 buffer, 32,
                                 buffer, sizeof( buffer ), &length ) );
    SMOKE_ASSERT( psa_verify_hash( handle, PSA_ALG_ECDSA_ANY,
                                   buffer, 32,
                                   buffer, sizeof( buffer ) ) );

    SMOKE_ASSERT( psa_asymmetric_encrypt( handle, PSA_ALG_RSA_PKCS1V15_CRYPT,
                                          buffer, 10, NULL, 0,
                                          buffer, sizeof( buffer ), &length ) );
    SMOKE_ASSERT( psa_asymmetric_decrypt( handle, PSA_ALG_RSA_PKCS1V15_CRYPT,
                                          buffer, sizeof( buffer ), NULL, 0,
                                          buffer, sizeof( buffer ), &length ) );

#if defined(MBEDTLS_SHA256_C)
    /* Try the key in a plain key derivation. */
    PSA_ASSERT( psa_key_derivation_setup( &derivation_operation,
                                          PSA_ALG_HKDF( PSA_ALG_SHA_256 ) ) );
    PSA_ASSERT( psa_key_derivation_input_bytes( &derivation_operation,
                                                PSA_KEY_DERIVATION_INPUT_SALT,
                                                NULL, 0 ) );
    SMOKE_ASSERT( psa_key_derivation_input_key( &derivation_operation,
                                                PSA_KEY_DERIVATION_INPUT_SECRET,
                                                handle ) );
    PSA_ASSERT( psa_key_derivation_abort( &derivation_operation ) );

    /* If the key is asymmetric, try it in a key agreement, both as
     * part of a derivation operation and standalone. */
    if( psa_export_public_key( handle, buffer, sizeof( buffer ), &length ) ==
        PSA_SUCCESS )
    {
        psa_algorithm_t alg =
            PSA_ALG_KEY_AGREEMENT( PSA_ALG_ECDH,
                                   PSA_ALG_HKDF( PSA_ALG_SHA_256 ) );
        PSA_ASSERT( psa_key_derivation_setup( &derivation_operation, alg ) );
        PSA_ASSERT( psa_key_derivation_input_bytes(
                        &derivation_operation, PSA_KEY_DERIVATION_INPUT_SALT,
                        NULL, 0 ) );
        SMOKE_ASSERT( psa_key_derivation_key_agreement(
                          &derivation_operation,
                          PSA_KEY_DERIVATION_INPUT_SECRET,
                          handle, buffer, length ) );
        PSA_ASSERT( psa_key_derivation_abort( &derivation_operation ) );

        SMOKE_ASSERT( psa_raw_key_agreement(
                          alg, handle, buffer, length,
                          buffer, sizeof( buffer ), &length ) );
    }
#endif /* MBEDTLS_SHA256_C */

    ok = 1;

exit:
    psa_reset_key_attributes( &attributes );
    return( ok );
}

#define MAX_KEY_ID_FOR_TEST 10
static void psa_purge_storage( void )
{
    psa_key_id_t id;
    psa_key_lifetime_t lifetime;
    /* The tests may have potentially created key ids from 1 to
     * MAX_KEY_ID_FOR_TEST. In addition, run the destroy function on key id
     * 0, which file-based storage uses as a temporary file. */
    for( id = 0; id <= MAX_KEY_ID_FOR_TEST; id++ )
        psa_destroy_persistent_key( id );
    /* Purge the transaction file. */
    psa_crypto_stop_transaction( );
    /* Purge driver persistent data. */
    for( lifetime = 0; lifetime < PSA_MAX_SE_LIFETIME; lifetime++ )
        psa_destroy_se_persistent_data( lifetime );
}

#line 761 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_register_one( int lifetime, int version, int expected_status_arg )
{
    psa_status_t expected_status = expected_status_arg;
    psa_drv_se_t driver;

    memset( &driver, 0, sizeof( driver ) );
    driver.hal_version = version;

    TEST_EQUAL( psa_register_se_driver( lifetime, &driver ),
                expected_status );

    PSA_ASSERT( psa_crypto_init( ) );

exit:
    PSA_DONE( );
}

void test_register_one_wrapper( void ** params )
{

    test_register_one( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 780 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_register_twice( int count )
{
    psa_drv_se_t driver;
    psa_key_lifetime_t lifetime;
    psa_key_lifetime_t max = MIN_DRIVER_LIFETIME + count;

    memset( &driver, 0, sizeof( driver ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;

    for( lifetime = MIN_DRIVER_LIFETIME; lifetime < max; lifetime++ )
        PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    for( lifetime = MIN_DRIVER_LIFETIME; lifetime < max; lifetime++ )
        TEST_EQUAL( psa_register_se_driver( lifetime, &driver ),
                    PSA_ERROR_ALREADY_EXISTS );

    PSA_ASSERT( psa_crypto_init( ) );

exit:
    PSA_DONE( );
}

void test_register_twice_wrapper( void ** params )
{

    test_register_twice( *( (int *) params[0] ) );
}
#line 803 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_register_max( )
{
    psa_drv_se_t driver;
    psa_key_lifetime_t lifetime;
    psa_key_lifetime_t max = MIN_DRIVER_LIFETIME + PSA_MAX_SE_DRIVERS;

    memset( &driver, 0, sizeof( driver ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;

    for( lifetime = MIN_DRIVER_LIFETIME; lifetime < max; lifetime++ )
        PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );

    TEST_EQUAL( psa_register_se_driver( lifetime, &driver ),
                PSA_ERROR_INSUFFICIENT_MEMORY );

    PSA_ASSERT( psa_crypto_init( ) );

exit:
    PSA_DONE( );
}

void test_register_max_wrapper( void ** params )
{
    (void)params;

    test_register_max(  );
}
#line 826 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_key_creation_import_export( int min_slot, int restart )
{
    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_key_lifetime_t lifetime = 2;
    psa_key_id_t id = 1;
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    const uint8_t key_material[3] = {0xfa, 0xca, 0xde};
    uint8_t exported[sizeof( key_material )];
    size_t exported_length;

    memset( &driver, 0, sizeof( driver ) );
    memset( &key_management, 0, sizeof( key_management ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    driver.key_management = &key_management;
    driver.persistent_data_size = sizeof( ram_slot_usage_t );
    key_management.p_allocate = ram_allocate;
    key_management.p_import = ram_import;
    key_management.p_destroy = ram_destroy;
    key_management.p_export = ram_export;
    ram_min_slot = min_slot;

    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    /* Create a key. */
    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_RAW_DATA );
    PSA_ASSERT( psa_import_key( &attributes,
                                key_material, sizeof( key_material ),
                                &handle ) );
    if( ! check_persistent_data( lifetime,
                                 &ram_shadow_slot_usage,
                                 sizeof( ram_shadow_slot_usage ) ) )
        goto exit;

    /* Maybe restart, to check that the information is saved correctly. */
    if( restart )
    {
        mbedtls_psa_crypto_free( );
        PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
        PSA_ASSERT( psa_crypto_init( ) );
        if( ! check_persistent_data( lifetime,
                                     &ram_shadow_slot_usage,
                                     sizeof( ram_shadow_slot_usage ) ) )
            goto exit;
        PSA_ASSERT( psa_open_key( id, &handle ) );
    }

    /* Test that the key was created in the expected slot. */
    TEST_ASSERT( ram_slots[min_slot].type == PSA_KEY_TYPE_RAW_DATA );

    /* Test the key attributes, including the reported slot number. */
    psa_set_key_bits( &attributes,
                      PSA_BYTES_TO_BITS( sizeof( key_material ) ) );
    psa_set_key_slot_number( &attributes, min_slot );
    if( ! check_key_attributes( handle, &attributes ) )
        goto exit;

    /* Test the key data. */
    PSA_ASSERT( psa_export_key( handle,
                                exported, sizeof( exported ),
                                &exported_length ) );
    ASSERT_COMPARE( key_material, sizeof( key_material ),
                    exported, exported_length );

    PSA_ASSERT( psa_destroy_key( handle ) );
    handle = 0;
    if( ! check_persistent_data( lifetime,
                                 &ram_shadow_slot_usage,
                                 sizeof( ram_shadow_slot_usage ) ) )
        goto exit;
    TEST_EQUAL( psa_open_key( id, &handle ),
                PSA_ERROR_DOES_NOT_EXIST );

    /* Test that the key has been erased from the designated slot. */
    TEST_ASSERT( ram_slots[min_slot].type == 0 );

exit:
    PSA_DONE( );
    ram_slots_reset( );
    psa_purge_storage( );
}

void test_key_creation_import_export_wrapper( void ** params )
{

    test_key_creation_import_export( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#line 915 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_key_creation_in_chosen_slot( int slot_arg,
                                  int restart,
                                  int expected_status_arg )
{
    psa_key_slot_number_t wanted_slot = slot_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_status_t status;
    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_key_lifetime_t lifetime = 2;
    psa_key_id_t id = 1;
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    const uint8_t key_material[3] = {0xfa, 0xca, 0xde};

    memset( &driver, 0, sizeof( driver ) );
    memset( &key_management, 0, sizeof( key_management ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    driver.key_management = &key_management;
    driver.persistent_data_size = sizeof( ram_slot_usage_t );
    key_management.p_validate_slot_number = ram_validate_slot_number;
    key_management.p_import = ram_import;
    key_management.p_destroy = ram_destroy;
    key_management.p_export = ram_export;

    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    /* Create a key. */
    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_RAW_DATA );
    psa_set_key_slot_number( &attributes, wanted_slot );
    status = psa_import_key( &attributes,
                             key_material, sizeof( key_material ),
                             &handle );
    TEST_EQUAL( status, expected_status );

    if( status != PSA_SUCCESS )
        goto exit;
    if( ! check_persistent_data( lifetime,
                                 &ram_shadow_slot_usage,
                                 sizeof( ram_shadow_slot_usage ) ) )
        goto exit;

    /* Maybe restart, to check that the information is saved correctly. */
    if( restart )
    {
        mbedtls_psa_crypto_free( );
        PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
        PSA_ASSERT( psa_crypto_init( ) );
        if( ! check_persistent_data( lifetime,
                                     &ram_shadow_slot_usage,
                                     sizeof( ram_shadow_slot_usage ) ) )
            goto exit;
        PSA_ASSERT( psa_open_key( id, &handle ) );
    }

    /* Test that the key was created in the expected slot. */
    TEST_EQUAL( ram_slots[wanted_slot].type, PSA_KEY_TYPE_RAW_DATA );

    /* Test that the key is reported with the correct attributes,
     * including the expected slot. */
    PSA_ASSERT( psa_get_key_attributes( handle, &attributes ) );

    PSA_ASSERT( psa_destroy_key( handle ) );
    handle = 0;
    if( ! check_persistent_data( lifetime,
                                 &ram_shadow_slot_usage,
                                 sizeof( ram_shadow_slot_usage ) ) )
        goto exit;
    TEST_EQUAL( psa_open_key( id, &handle ),
                PSA_ERROR_DOES_NOT_EXIST );

exit:
    PSA_DONE( );
    ram_slots_reset( );
    psa_purge_storage( );
}

void test_key_creation_in_chosen_slot_wrapper( void ** params )
{

    test_key_creation_in_chosen_slot( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 998 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_import_key_smoke( int type_arg, int alg_arg,
                       data_t *key_material )
{
    psa_key_type_t type = type_arg;
    psa_algorithm_t alg = alg_arg;
    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_key_lifetime_t lifetime = 2;
    psa_key_id_t id = 1;
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    memset( &driver, 0, sizeof( driver ) );
    memset( &key_management, 0, sizeof( key_management ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    driver.key_management = &key_management;
    driver.persistent_data_size = sizeof( psa_key_slot_number_t );
    key_management.p_allocate = counter_allocate;
    key_management.p_import = null_import;
    key_management.p_destroy = null_destroy;

    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    /* Create a key. */
    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_usage_flags( &attributes,
                             PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH |
                             PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT |
                             PSA_KEY_USAGE_EXPORT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );
    PSA_ASSERT( psa_import_key( &attributes,
                                key_material->x, key_material->len,
                                &handle ) );
    if( ! check_persistent_data( lifetime,
                                 &shadow_counter, sizeof( shadow_counter ) ) )
        goto exit;

    /* Do stuff with the key. */
    if( ! smoke_test_key( handle ) )
        goto exit;

    /* Restart and try again. */
    mbedtls_psa_crypto_free( );
    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );
    if( ! check_persistent_data( lifetime,
                                 &shadow_counter, sizeof( shadow_counter ) ) )
        goto exit;
    PSA_ASSERT( psa_open_key( id, &handle ) );
    if( ! smoke_test_key( handle ) )
        goto exit;

    /* We're done. */
    PSA_ASSERT( psa_destroy_key( handle ) );
    handle = 0;
    if( ! check_persistent_data( lifetime,
                                 &shadow_counter, sizeof( shadow_counter ) ) )
        goto exit;
    TEST_EQUAL( psa_open_key( id, &handle ),
                PSA_ERROR_DOES_NOT_EXIST );

exit:
    PSA_DONE( );
    counter_reset( );
    psa_purge_storage( );
}

void test_import_key_smoke_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_import_key_smoke( *( (int *) params[0] ), *( (int *) params[1] ), &data2 );
}
#line 1070 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_generate_key_not_supported( int type_arg, int bits_arg )
{
    psa_key_type_t type = type_arg;
    size_t bits = bits_arg;
    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_key_lifetime_t lifetime = 2;
    psa_key_id_t id = 1;
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    memset( &driver, 0, sizeof( driver ) );
    memset( &key_management, 0, sizeof( key_management ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    driver.key_management = &key_management;
    driver.persistent_data_size = sizeof( psa_key_slot_number_t );
    key_management.p_allocate = counter_allocate;
    /* No p_generate method */

    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_type( &attributes, type );
    psa_set_key_bits( &attributes, bits );
    TEST_EQUAL( psa_generate_key( &attributes, &handle ),
                PSA_ERROR_NOT_SUPPORTED );

exit:
    PSA_DONE( );
    counter_reset( );
    psa_purge_storage( );
}

void test_generate_key_not_supported_wrapper( void ** params )
{

    test_generate_key_not_supported( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#line 1107 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_generate_key_smoke( int type_arg, int bits_arg, int alg_arg )
{
    psa_key_type_t type = type_arg;
    psa_key_bits_t bits = bits_arg;
    psa_algorithm_t alg = alg_arg;
    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_key_lifetime_t lifetime = 2;
    psa_key_id_t id = 1;
    psa_key_handle_t handle = 0;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;

    memset( &driver, 0, sizeof( driver ) );
    memset( &key_management, 0, sizeof( key_management ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    driver.key_management = &key_management;
    driver.persistent_data_size = sizeof( psa_key_slot_number_t );
    key_management.p_allocate = counter_allocate;
    key_management.p_generate = null_generate;
    key_management.p_destroy = null_destroy;

    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    /* Create a key. */
    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_usage_flags( &attributes,
                             PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH |
                             PSA_KEY_USAGE_ENCRYPT | PSA_KEY_USAGE_DECRYPT |
                             PSA_KEY_USAGE_EXPORT );
    psa_set_key_algorithm( &attributes, alg );
    psa_set_key_type( &attributes, type );
    psa_set_key_bits( &attributes, bits );
    PSA_ASSERT( psa_generate_key( &attributes, &handle ) );
    if( ! check_persistent_data( lifetime,
                                 &shadow_counter, sizeof( shadow_counter ) ) )
        goto exit;

    /* Do stuff with the key. */
    if( ! smoke_test_key( handle ) )
        goto exit;

    /* Restart and try again. */
    mbedtls_psa_crypto_free( );
    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );
    if( ! check_persistent_data( lifetime,
                                 &shadow_counter, sizeof( shadow_counter ) ) )
        goto exit;
    PSA_ASSERT( psa_open_key( id, &handle ) );
    if( ! smoke_test_key( handle ) )
        goto exit;

    /* We're done. */
    PSA_ASSERT( psa_destroy_key( handle ) );
    handle = 0;
    if( ! check_persistent_data( lifetime,
                                 &shadow_counter, sizeof( shadow_counter ) ) )
        goto exit;
    TEST_EQUAL( psa_open_key( id, &handle ),
                PSA_ERROR_DOES_NOT_EXIST );

exit:
    PSA_DONE( );
    counter_reset( );
    psa_purge_storage( );
}

void test_generate_key_smoke_wrapper( void ** params )
{

    test_generate_key_smoke( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 1178 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_sign_verify( int flow,
                  int type_arg, int alg_arg,
                  int bits_arg, data_t *key_material,
                  data_t *input )
{
    psa_key_type_t type = type_arg;
    psa_algorithm_t alg = alg_arg;
    size_t bits = bits_arg;
    /* Pass bits=0 to import, bits>0 to fake-generate */
    int generating = ( bits != 0 );

    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_drv_se_asymmetric_t asymmetric;

    psa_key_lifetime_t lifetime = 2;
    psa_key_id_t id = 1;
    psa_key_handle_t drv_handle = 0; /* key managed by the driver */
    psa_key_handle_t sw_handle = 0; /* transparent key */
    psa_key_attributes_t sw_attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_attributes_t drv_attributes;
    uint8_t signature[PSA_SIGNATURE_MAX_SIZE];
    size_t signature_length;

    memset( &driver, 0, sizeof( driver ) );
    memset( &key_management, 0, sizeof( key_management ) );
    memset( &asymmetric, 0, sizeof( asymmetric ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    driver.key_management = &key_management;
    driver.asymmetric = &asymmetric;
    driver.persistent_data_size = sizeof( ram_slot_usage_t );
    key_management.p_allocate = ram_allocate;
    key_management.p_destroy = ram_destroy;
    if( generating )
        key_management.p_generate = ram_fake_generate;
    else
        key_management.p_import = ram_import;
    switch( flow )
    {
        case SIGN_IN_SOFTWARE_AND_PARALLEL_CREATION:
            break;
        case SIGN_IN_DRIVER_AND_PARALLEL_CREATION:
            asymmetric.p_sign = ram_sign;
            break;
        case SIGN_IN_DRIVER_THEN_EXPORT_PUBLIC:
            asymmetric.p_sign = ram_sign;
            key_management.p_export_public = ram_export_public;
            break;
        default:
            TEST_ASSERT( ! "unsupported flow (should be SIGN_IN_xxx)" );
            break;
    }
    asymmetric.p_verify = ram_verify;

    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    /* Prepare to create two keys with the same key material: a transparent
     * key, and one that goes through the driver. */
    psa_set_key_usage_flags( &sw_attributes,
                             PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH );
    psa_set_key_algorithm( &sw_attributes, alg );
    psa_set_key_type( &sw_attributes, type );
    drv_attributes = sw_attributes;
    psa_set_key_id( &drv_attributes, id );
    psa_set_key_lifetime( &drv_attributes, lifetime );

    /* Create the key in the driver. */
    if( generating )
    {
        psa_set_key_bits( &drv_attributes, bits );
        PSA_ASSERT( psa_generate_key( &drv_attributes, &drv_handle ) );
        /* Since we called a generate method that does not actually
         * generate material, store the desired result of generation in
         * the mock secure element storage. */
        PSA_ASSERT( psa_get_key_attributes( drv_handle, &drv_attributes ) );
        TEST_ASSERT( key_material->len == PSA_BITS_TO_BYTES( bits ) );
        memcpy( ram_slots[ram_min_slot].content, key_material->x,
                key_material->len );
    }
    else
    {
        PSA_ASSERT( psa_import_key( &drv_attributes,
                                    key_material->x, key_material->len,
                                    &drv_handle ) );
    }

    /* Either import the same key in software, or export the driver's
     * public key and import that. */
    switch( flow )
    {
        case SIGN_IN_SOFTWARE_AND_PARALLEL_CREATION:
        case SIGN_IN_DRIVER_AND_PARALLEL_CREATION:
            PSA_ASSERT( psa_import_key( &sw_attributes,
                                        key_material->x, key_material->len,
                                        &sw_handle ) );
            break;
        case SIGN_IN_DRIVER_THEN_EXPORT_PUBLIC:
        {
            uint8_t public_key[PSA_KEY_EXPORT_ECC_PUBLIC_KEY_MAX_SIZE( PSA_VENDOR_ECC_MAX_CURVE_BITS )];
            size_t public_key_length;
            PSA_ASSERT( psa_export_public_key( drv_handle,
                                               public_key, sizeof( public_key ),
                                               &public_key_length ) );
            psa_set_key_type( &sw_attributes,
                              PSA_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR( type ) );
            PSA_ASSERT( psa_import_key( &sw_attributes,
                                        public_key, public_key_length,
                                        &sw_handle ) );
            break;
        }
    }

    /* Sign with the chosen key. */
    switch( flow )
    {
        case SIGN_IN_DRIVER_AND_PARALLEL_CREATION:
        case SIGN_IN_DRIVER_THEN_EXPORT_PUBLIC:
            PSA_ASSERT_VIA_DRIVER(
                psa_sign_hash( drv_handle,
                               alg,
                               input->x, input->len,
                               signature, sizeof( signature ),
                               &signature_length ),
                PSA_SUCCESS );
            break;
        case SIGN_IN_SOFTWARE_AND_PARALLEL_CREATION:
            PSA_ASSERT( psa_sign_hash( sw_handle,
                                       alg,
                                       input->x, input->len,
                                       signature, sizeof( signature ),
                                       &signature_length ) );
            break;
    }

    /* Verify with both keys. */
    PSA_ASSERT( psa_verify_hash( sw_handle, alg,
                                 input->x, input->len,
                                 signature, signature_length ) );
    PSA_ASSERT_VIA_DRIVER(
        psa_verify_hash( drv_handle, alg,
                         input->x, input->len,
                         signature, signature_length ),
        PSA_SUCCESS );

    /* Change the signature and verify again. */
    signature[0] ^= 1;
    TEST_EQUAL( psa_verify_hash( sw_handle, alg,
                                 input->x, input->len,
                                 signature, signature_length ),
                PSA_ERROR_INVALID_SIGNATURE );
    PSA_ASSERT_VIA_DRIVER(
        psa_verify_hash( drv_handle, alg,
                         input->x, input->len,
                         signature, signature_length ),
        PSA_ERROR_INVALID_SIGNATURE );

exit:
    psa_destroy_key( drv_handle );
    psa_destroy_key( sw_handle );
    PSA_DONE( );
    ram_slots_reset( );
    psa_purge_storage( );
}

void test_sign_verify_wrapper( void ** params )
{
    data_t data4 = {(uint8_t *) params[4], *( (uint32_t *) params[5] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_sign_verify( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), &data4, &data6 );
}
#line 1345 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_psa_crypto_se_driver_hal.function"
void test_register_key_smoke_test( int lifetime_arg,
                              int validate,
                              int expected_status_arg )
{
    psa_key_lifetime_t lifetime = lifetime_arg;
    psa_status_t expected_status = expected_status_arg;
    psa_drv_se_t driver;
    psa_drv_se_key_management_t key_management;
    psa_key_attributes_t attributes = PSA_KEY_ATTRIBUTES_INIT;
    psa_key_id_t id = 1;
    size_t bit_size = 48;
    psa_key_slot_number_t wanted_slot = 0x123456789;
    psa_key_handle_t handle = 0;
    psa_status_t status;

    memset( &driver, 0, sizeof( driver ) );
    driver.hal_version = PSA_DRV_SE_HAL_VERSION;
    memset( &key_management, 0, sizeof( key_management ) );
    driver.key_management = &key_management;
    key_management.p_destroy = null_destroy;
    if( validate >= 0 )
    {
        key_management.p_validate_slot_number = validate_slot_number_as_directed;
        validate_slot_number_directions.slot_number = wanted_slot;
        validate_slot_number_directions.method = PSA_KEY_CREATION_REGISTER;
        validate_slot_number_directions.status =
            ( validate > 0 ? PSA_SUCCESS : PSA_ERROR_NOT_PERMITTED );
    }

    PSA_ASSERT( psa_register_se_driver( MIN_DRIVER_LIFETIME, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );

    psa_set_key_id( &attributes, id );
    psa_set_key_lifetime( &attributes, lifetime );
    psa_set_key_usage_flags( &attributes, PSA_KEY_USAGE_EXPORT );
    psa_set_key_type( &attributes, PSA_KEY_TYPE_RAW_DATA );
    psa_set_key_bits( &attributes, bit_size );
    psa_set_key_slot_number( &attributes, wanted_slot );

    status = mbedtls_psa_register_se_key( &attributes );
    TEST_EQUAL( status, expected_status );

    if( status != PSA_SUCCESS )
        goto exit;

    /* Test that the key exists and has the expected attributes. */
    PSA_ASSERT( psa_open_key( id, &handle ) );
    if( ! check_key_attributes( handle, &attributes ) )
        goto exit;
    PSA_ASSERT( psa_close_key( handle ) );

    /* Restart and try again. */
    PSA_DONE( );
    PSA_ASSERT( psa_register_se_driver( lifetime, &driver ) );
    PSA_ASSERT( psa_crypto_init( ) );
    PSA_ASSERT( psa_open_key( id, &handle ) );
    if( ! check_key_attributes( handle, &attributes ) )
        goto exit;
    /* This time, destroy the key. */
    PSA_ASSERT( psa_destroy_key( handle ) );
    handle = 0;
    TEST_EQUAL( psa_open_key( id, &handle ),
                PSA_ERROR_DOES_NOT_EXIST );

exit:
    psa_reset_key_attributes( &attributes );
    psa_destroy_key( handle );
    PSA_DONE( );
    psa_purge_storage( );
    memset( &validate_slot_number_directions, 0,
            sizeof( validate_slot_number_directions ) );
}

void test_register_key_smoke_test_wrapper( void ** params )
{

    test_register_key_smoke_test( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* MBEDTLS_PSA_CRYPTO_SE_C */


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

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)

        case 0:
            {
                *out_value = PSA_DRV_SE_HAL_VERSION;
            }
            break;
        case 1:
            {
                *out_value = PSA_SUCCESS;
            }
            break;
        case 2:
            {
                *out_value = PSA_ERROR_INVALID_ARGUMENT;
            }
            break;
        case 3:
            {
                *out_value = PSA_KEY_LIFETIME_VOLATILE;
            }
            break;
        case 4:
            {
                *out_value = PSA_KEY_LIFETIME_PERSISTENT;
            }
            break;
        case 5:
            {
                *out_value = PSA_ERROR_NOT_SUPPORTED;
            }
            break;
        case 6:
            {
                *out_value = PSA_DRV_SE_HAL_VERSION + 1;
            }
            break;
        case 7:
            {
                *out_value = ARRAY_LENGTH( ram_slots ) - 1;
            }
            break;
        case 8:
            {
                *out_value = ARRAY_LENGTH( ram_slots );
            }
            break;
        case 9:
            {
                *out_value = PSA_KEY_TYPE_AES;
            }
            break;
        case 10:
            {
                *out_value = PSA_ALG_CTR;
            }
            break;
        case 11:
            {
                *out_value = PSA_ALG_CBC_NO_PADDING;
            }
            break;
        case 12:
            {
                *out_value = PSA_ALG_CMAC;
            }
            break;
        case 13:
            {
                *out_value = PSA_ALG_CCM;
            }
            break;
        case 14:
            {
                *out_value = PSA_ALG_GCM;
            }
            break;
        case 15:
            {
                *out_value = PSA_KEY_TYPE_CAMELLIA;
            }
            break;
        case 16:
            {
                *out_value = PSA_KEY_TYPE_HMAC;
            }
            break;
        case 17:
            {
                *out_value = PSA_ALG_HMAC( PSA_ALG_SHA_256 );
            }
            break;
        case 18:
            {
                *out_value = PSA_KEY_TYPE_DERIVE;
            }
            break;
        case 19:
            {
                *out_value = PSA_ALG_HKDF( PSA_ALG_SHA_256 );
            }
            break;
        case 20:
            {
                *out_value = PSA_KEY_TYPE_RSA_KEY_PAIR;
            }
            break;
        case 21:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_SIGN_RAW;
            }
            break;
        case 22:
            {
                *out_value = PSA_ALG_RSA_PKCS1V15_CRYPT;
            }
            break;
        case 23:
            {
                *out_value = PSA_ALG_RSA_OAEP( PSA_ALG_SHA_256 );
            }
            break;
        case 24:
            {
                *out_value = PSA_KEY_TYPE_ECC_KEY_PAIR( PSA_ECC_CURVE_SECP_R1 );
            }
            break;
        case 25:
            {
                *out_value = PSA_ALG_ECDSA_ANY;
            }
            break;
        case 26:
            {
                *out_value = PSA_ALG_ECDH;
            }
            break;
        case 27:
            {
                *out_value = PSA_ALG_KEY_AGREEMENT( PSA_ALG_ECDH, PSA_ALG_HKDF( PSA_ALG_SHA_256 ) );
            }
            break;
        case 28:
            {
                *out_value = MIN_DRIVER_LIFETIME;
            }
            break;
        case 29:
            {
                *out_value = MIN_DRIVER_LIFETIME + 1;
            }
            break;
        case 30:
            {
                *out_value = PSA_ERROR_NOT_PERMITTED;
            }
            break;
        case 31:
            {
                *out_value = -1;
            }
            break;
        case 32:
            {
                *out_value = SIGN_IN_DRIVER_AND_PARALLEL_CREATION;
            }
            break;
        case 33:
            {
                *out_value = SIGN_IN_DRIVER_THEN_EXPORT_PUBLIC;
            }
            break;
        case 34:
            {
                *out_value = SIGN_IN_SOFTWARE_AND_PARALLEL_CREATION;
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

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)

        case 0:
            {
#if defined(MBEDTLS_ECDSA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
            {
#if defined(MBEDTLS_ECP_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 2:
            {
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
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

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_register_one_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_register_twice_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_register_max_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_key_creation_import_export_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_key_creation_in_chosen_slot_wrapper,
#else
    NULL,
#endif
/* Function Id: 5 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_import_key_smoke_wrapper,
#else
    NULL,
#endif
/* Function Id: 6 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_generate_key_not_supported_wrapper,
#else
    NULL,
#endif
/* Function Id: 7 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_generate_key_smoke_wrapper,
#else
    NULL,
#endif
/* Function Id: 8 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_sign_verify_wrapper,
#else
    NULL,
#endif
/* Function Id: 9 */

#if defined(MBEDTLS_PSA_CRYPTO_SE_C)
    test_register_key_smoke_test_wrapper,
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
    const char *default_filename = "./test_suite_psa_crypto_se_driver_hal.datax";
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
