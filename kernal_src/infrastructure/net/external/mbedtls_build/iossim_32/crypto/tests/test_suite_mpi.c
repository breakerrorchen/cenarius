#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_mpi.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/main_test.function
 *      Platform code file  : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/host_test.function
 *      Helper file         : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/helpers.function
 *      Test suite file     : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function
 *      Test suite data     : /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.data
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

#if defined(MBEDTLS_BIGNUM_C)
#line 2 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
#include "mbedtls/bignum.h"

typedef struct mbedtls_test_mpi_random
{
    data_t *data;
    size_t  pos;
    size_t  chunk_len;
} mbedtls_test_mpi_random;

/*
 * This function is called by the Miller-Rabin primality test each time it
 * chooses a random witness. The witnesses (or non-witnesses as provided by the
 * test) are stored in the data member of the state structure. Each number is in
 * the format that mbedtls_mpi_read_string understands and is chunk_len long.
 */
int mbedtls_test_mpi_miller_rabin_determinizer( void* state,
                                                unsigned char* buf,
                                                size_t len )
{
    mbedtls_test_mpi_random *random = (mbedtls_test_mpi_random*) state;

    if( random == NULL || random->data->x == NULL || buf == NULL )
        return( -1 );

    if( random->pos + random->chunk_len > random->data->len
            || random->chunk_len > len )
    {
        return( -1 );
    }

    memset( buf, 0, len );

    /* The witness is written to the end of the buffer, since the buffer is
     * used as big endian, unsigned binary data in mbedtls_mpi_read_binary.
     * Writing the witness to the start of the buffer would result in the
     * buffer being 'witness 000...000', which would be treated as
     * witness * 2^n for some n. */
    memcpy( buf + len - random->chunk_len, &random->data->x[random->pos],
            random->chunk_len );

    random->pos += random->chunk_len;

    return( 0 );
}
#line 54 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_valid_param( )
{
    TEST_VALID_PARAM( mbedtls_mpi_free( NULL ) );
exit:
    ;
}

void test_mpi_valid_param_wrapper( void ** params )
{
    (void)params;

    test_mpi_valid_param(  );
}
#if defined(MBEDTLS_CHECK_PARAMS)
#if !defined(MBEDTLS_PARAM_FAILED_ALT)
#line 61 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_invalid_param( )
{
    mbedtls_mpi X;
    const char *s_in = "00101000101010";
    char s_out[16] = { 0 };
    unsigned char u_out[16] = { 0 };
    unsigned char u_in[16] = { 0 };
    size_t olen;
    mbedtls_mpi_uint mpi_uint;

    TEST_INVALID_PARAM( mbedtls_mpi_init( NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_grow( NULL, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_copy( NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_copy( &X, NULL ) );

    TEST_INVALID_PARAM( mbedtls_mpi_swap( NULL, &X ) );
    TEST_INVALID_PARAM( mbedtls_mpi_swap( &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_safe_cond_assign( NULL, &X, 0 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_safe_cond_assign( &X, NULL, 0 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_safe_cond_swap( NULL, &X, 0 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_safe_cond_swap( &X, NULL, 0 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_lset( NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_get_bit( NULL, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_set_bit( NULL, 42, 0 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_read_string( NULL, 2, s_in ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_read_string( &X, 2, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_write_string( NULL, 2,
                                                      s_out, sizeof( s_out ),
                                                      &olen ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_write_string( &X, 2,
                                                      NULL, sizeof( s_out ),
                                                      &olen ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_write_string( &X, 2,
                                                      s_out, sizeof( s_out ),
                                                      NULL ) );

#if defined(MBEDTLS_FS_IO)
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_read_file( NULL, 2, stdin ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_read_file( &X, 2, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_write_file( "", NULL, 2, NULL ) );
#endif /* MBEDTLS_FS_IO */

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_read_binary( NULL, u_in,
                                                     sizeof( u_in ) ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_read_binary( &X, NULL,
                                                     sizeof( u_in ) ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_write_binary( NULL, u_out,
                                                      sizeof( u_out ) ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_write_binary( &X, NULL,
                                                      sizeof( u_out ) ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_shift_l( NULL, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_shift_r( NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_cmp_abs( NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_cmp_abs( &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_cmp_mpi( NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_cmp_mpi( &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_cmp_int( NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_abs( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_abs( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_abs( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_abs( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_abs( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_abs( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_mpi( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_mpi( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_mpi( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_mpi( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_mpi( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_mpi( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_int( NULL, &X, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_add_int( &X, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_int( NULL, &X, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_sub_int( &X, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mul_mpi( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mul_mpi( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mul_mpi( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mul_int( NULL, &X, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mul_int( &X, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_div_mpi( &X, &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_div_mpi( &X, &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_div_int( &X, &X, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( 0, mbedtls_mpi_lsb( NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mod_mpi( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mod_mpi( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mod_mpi( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mod_int( NULL, &X, 42 ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_mod_int( &mpi_uint, NULL, 42 ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_exp_mod( NULL, &X, &X, &X, NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_exp_mod( &X, NULL, &X, &X, NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_exp_mod( &X, &X, NULL, &X, NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_exp_mod( &X, &X, &X, NULL, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_fill_random( NULL, 42, rnd_std_rand,
                                                     NULL ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_fill_random( &X, 42, NULL, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_gcd( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_gcd( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_gcd( &X, &X, NULL ) );

    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_inv_mod( NULL, &X, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_inv_mod( &X, NULL, &X ) );
    TEST_INVALID_PARAM_RET( MBEDTLS_ERR_MPI_BAD_INPUT_DATA,
                            mbedtls_mpi_inv_mod( &X, &X, NULL ) );

exit:
    return;
}

void test_mpi_invalid_param_wrapper( void ** params )
{
    (void)params;

    test_mpi_invalid_param(  );
}
#endif /* !MBEDTLS_PARAM_FAILED_ALT */
#endif /* MBEDTLS_CHECK_PARAMS */
#line 268 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_null(  )
{
    mbedtls_mpi X, Y, Z;

    mbedtls_mpi_init( &X );
    mbedtls_mpi_init( &Y );
    mbedtls_mpi_init( &Z );

    TEST_ASSERT( mbedtls_mpi_get_bit( &X, 42 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_lsb( &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_bitlen( &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_size( &X ) == 0 );

exit:
    mbedtls_mpi_free( &X );
}

void test_mpi_null_wrapper( void ** params )
{
    (void)params;

    test_mpi_null(  );
}
#line 287 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_read_write_string( int radix_X, char * input_X, int radix_A,
                            char * input_A, int output_size, int result_read,
                            int result_write )
{
    mbedtls_mpi X;
    char str[1000];
    size_t len;

    mbedtls_mpi_init( &X );

    memset( str, '!', sizeof( str ) );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == result_read );
    if( result_read == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_write_string( &X, radix_A, str, output_size, &len ) == result_write );
        if( result_write == 0 )
        {
            TEST_ASSERT( strcasecmp( str, input_A ) == 0 );
            TEST_ASSERT( str[len] == '!' );
        }
    }

exit:
    mbedtls_mpi_free( &X );
}

void test_mpi_read_write_string_wrapper( void ** params )
{

    test_mpi_read_write_string( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ) );
}
#line 316 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_read_binary( data_t * buf, int radix_A, char * input_A )
{
    mbedtls_mpi X;
    char str[1000];
    size_t len;

    mbedtls_mpi_init( &X );


    TEST_ASSERT( mbedtls_mpi_read_binary( &X, buf->x, buf->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_write_string( &X, radix_A, str, sizeof( str ), &len ) == 0 );
    TEST_ASSERT( strcmp( (char *) str, input_A ) == 0 );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_read_binary_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_mbedtls_mpi_read_binary( &data0, *( (int *) params[2] ), (char *) params[3] );
}
#line 335 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_read_binary_le( data_t * buf, int radix_A, char * input_A )
{
    mbedtls_mpi X;
    char str[1000];
    size_t len;

    mbedtls_mpi_init( &X );


    TEST_ASSERT( mbedtls_mpi_read_binary_le( &X, buf->x, buf->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_write_string( &X, radix_A, str, sizeof( str ), &len ) == 0 );
    TEST_ASSERT( strcmp( (char *) str, input_A ) == 0 );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_read_binary_le_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_mbedtls_mpi_read_binary_le( &data0, *( (int *) params[2] ), (char *) params[3] );
}
#line 354 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_write_binary( int radix_X, char * input_X,
                               data_t * input_A, int output_size,
                               int result )
{
    mbedtls_mpi X;
    unsigned char buf[1000];
    size_t buflen;

    memset( buf, 0x00, 1000 );

    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );

    buflen = mbedtls_mpi_size( &X );
    if( buflen > (size_t) output_size )
        buflen = (size_t) output_size;

    TEST_ASSERT( mbedtls_mpi_write_binary( &X, buf, buflen ) == result );
    if( result == 0)
    {

        TEST_ASSERT( hexcmp( buf, input_A->x, buflen, input_A->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_write_binary_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_mbedtls_mpi_write_binary( *( (int *) params[0] ), (char *) params[1], &data2, *( (int *) params[4] ), *( (int *) params[5] ) );
}
#line 385 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_write_binary_le( int radix_X, char * input_X,
                                  data_t * input_A, int output_size,
                                  int result )
{
    mbedtls_mpi X;
    unsigned char buf[1000];
    size_t buflen;

    memset( buf, 0x00, 1000 );

    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );

    buflen = mbedtls_mpi_size( &X );
    if( buflen > (size_t) output_size )
        buflen = (size_t) output_size;

    TEST_ASSERT( mbedtls_mpi_write_binary_le( &X, buf, buflen ) == result );
    if( result == 0)
    {

        TEST_ASSERT( hexcmp( buf, input_A->x, buflen, input_A->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_write_binary_le_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_mbedtls_mpi_write_binary_le( *( (int *) params[0] ), (char *) params[1], &data2, *( (int *) params[4] ), *( (int *) params[5] ) );
}
#if defined(MBEDTLS_FS_IO)
#line 416 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_read_file( int radix_X, char * input_file,
                            data_t * input_A, int result )
{
    mbedtls_mpi X;
    unsigned char buf[1000];
    size_t buflen;
    FILE *file;
    int ret;

    memset( buf, 0x00, 1000 );

    mbedtls_mpi_init( &X );

    file = fopen( input_file, "r" );
    TEST_ASSERT( file != NULL );
    ret = mbedtls_mpi_read_file( &X, radix_X, file );
    fclose(file);
    TEST_ASSERT( ret == result );

    if( result == 0 )
    {
        buflen = mbedtls_mpi_size( &X );
        TEST_ASSERT( mbedtls_mpi_write_binary( &X, buf, buflen ) == 0 );


        TEST_ASSERT( hexcmp( buf, input_A->x, buflen, input_A->len ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_read_file_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_mbedtls_mpi_read_file( *( (int *) params[0] ), (char *) params[1], &data2, *( (int *) params[4] ) );
}
#endif /* MBEDTLS_FS_IO */
#if defined(MBEDTLS_FS_IO)
#line 450 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_write_file( int radix_X, char * input_X, int output_radix,
                             char * output_file )
{
    mbedtls_mpi X, Y;
    FILE *file_out, *file_in;
    int ret;

    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );

    file_out = fopen( output_file, "w" );
    TEST_ASSERT( file_out != NULL );
    ret = mbedtls_mpi_write_file( NULL, &X, output_radix, file_out );
    fclose(file_out);
    TEST_ASSERT( ret == 0 );

    file_in = fopen( output_file, "r" );
    TEST_ASSERT( file_in != NULL );
    ret = mbedtls_mpi_read_file( &Y, output_radix, file_in );
    fclose(file_in);
    TEST_ASSERT( ret == 0 );

    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &Y ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_write_file_wrapper( void ** params )
{

    test_mbedtls_mpi_write_file( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3] );
}
#endif /* MBEDTLS_FS_IO */
#line 481 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_get_bit( int radix_X, char * input_X, int pos, int val )
{
    mbedtls_mpi X;
    mbedtls_mpi_init( &X );
    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_get_bit( &X, pos ) == val );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_get_bit_wrapper( void ** params )
{

    test_mbedtls_mpi_get_bit( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ) );
}
#line 494 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_set_bit( int radix_X, char * input_X, int pos, int val,
                          int radix_Y, char * output_Y, int result )
{
    mbedtls_mpi X, Y;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, output_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_set_bit( &X, pos, val ) == result );

    if( result == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &Y ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_set_bit_wrapper( void ** params )
{

    test_mbedtls_mpi_set_bit( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ) );
}
#line 515 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_lsb( int radix_X, char * input_X, int nr_bits )
{
    mbedtls_mpi X;
    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_lsb( &X ) == (size_t) nr_bits );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_lsb_wrapper( void ** params )
{

    test_mbedtls_mpi_lsb( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ) );
}
#line 529 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_bitlen( int radix_X, char * input_X, int nr_bits )
{
    mbedtls_mpi X;
    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_bitlen( &X ) == (size_t) nr_bits );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_bitlen_wrapper( void ** params )
{

    test_mbedtls_mpi_bitlen( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ) );
}
#line 543 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_gcd( int radix_X, char * input_X, int radix_Y,
                      char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi A, X, Y, Z;
    mbedtls_mpi_init( &A ); mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_gcd( &Z, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &A ); mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z );
}

void test_mbedtls_mpi_gcd_wrapper( void ** params )
{

    test_mbedtls_mpi_gcd( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 561 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_cmp_int( int input_X, int input_A, int result_CMP )
{
    mbedtls_mpi X;
    mbedtls_mpi_init( &X  );

    TEST_ASSERT( mbedtls_mpi_lset( &X, input_X ) == 0);
    TEST_ASSERT( mbedtls_mpi_cmp_int( &X, input_A ) == result_CMP);

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_cmp_int_wrapper( void ** params )
{

    test_mbedtls_mpi_cmp_int( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#line 575 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_cmp_mpi( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int input_A )
{
    mbedtls_mpi X, Y;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &Y ) == input_A );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_cmp_mpi_wrapper( void ** params )
{

    test_mbedtls_mpi_cmp_mpi( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ) );
}
#line 591 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_lt_mpi_ct( int size_X, char * input_X,
                            int size_Y, char * input_Y,
                            int input_ret, int input_err )
{
    unsigned ret;
    unsigned input_uret = input_ret;
    mbedtls_mpi X, Y;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, 16, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, 16, input_Y ) == 0 );

    TEST_ASSERT( mbedtls_mpi_grow( &X, size_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_grow( &Y, size_Y ) == 0 );

    TEST_ASSERT( mbedtls_mpi_lt_mpi_ct( &X, &Y, &ret ) == input_err );
    if( input_err == 0 )
        TEST_ASSERT( ret == input_uret );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_lt_mpi_ct_wrapper( void ** params )
{

    test_mbedtls_mpi_lt_mpi_ct( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), *( (int *) params[5] ) );
}
#line 616 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_cmp_abs( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int input_A )
{
    mbedtls_mpi X, Y;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_abs( &X, &Y ) == input_A );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_cmp_abs_wrapper( void ** params )
{

    test_mbedtls_mpi_cmp_abs( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ) );
}
#line 632 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_copy_sint( int input_X, int input_Y )
{
    mbedtls_mpi X, Y;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_lset( &X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_lset( &Y, input_Y ) == 0 );

    TEST_ASSERT( mbedtls_mpi_copy( &Y, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &Y, input_X ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_copy_sint_wrapper( void ** params )
{

    test_mbedtls_mpi_copy_sint( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#line 650 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_copy_binary( data_t *input_X, data_t *input_Y )
{
    mbedtls_mpi X, Y, X0;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &X0 );

    TEST_ASSERT( mbedtls_mpi_read_binary( &X, input_X->x, input_X->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_binary( &Y, input_Y->x, input_Y->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_binary( &X0, input_X->x, input_X->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &X0 ) == 0 );

    TEST_ASSERT( mbedtls_mpi_copy( &Y, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &X0 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Y, &X0 ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &X0 );
}

void test_mbedtls_mpi_copy_binary_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_mbedtls_mpi_copy_binary( &data0, &data2 );
}
#line 670 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_copy_self( int input_X )
{
    mbedtls_mpi X;
    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_lset( &X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_copy( &X, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &X, input_X ) == 0 );

exit:
    mbedtls_mpi_free( &X );
}

void test_mpi_copy_self_wrapper( void ** params )
{

    test_mpi_copy_self( *( (int *) params[0] ) );
}
#line 685 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_shrink( int before, int used, int min, int after )
{
    mbedtls_mpi X;
    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_grow( &X, before ) == 0 );
    TEST_ASSERT( used <= before );
    memset( X.p, 0x2a, used * sizeof( mbedtls_mpi_uint ) );
    TEST_ASSERT( mbedtls_mpi_shrink( &X, min ) == 0 );
    TEST_ASSERT( X.n == (size_t) after );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_shrink_wrapper( void ** params )
{

    test_mbedtls_mpi_shrink( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ) );
}
#line 702 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_safe_cond_assign( int x_sign, char * x_str, int y_sign,
                                   char * y_str )
{
    mbedtls_mpi X, Y, XX;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &XX );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, 16, x_str ) == 0 );
    X.s = x_sign;
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, 16, y_str ) == 0 );
    Y.s = y_sign;
    TEST_ASSERT( mbedtls_mpi_copy( &XX, &X ) == 0 );

    TEST_ASSERT( mbedtls_mpi_safe_cond_assign( &X, &Y, 0 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &XX ) == 0 );

    TEST_ASSERT( mbedtls_mpi_safe_cond_assign( &X, &Y, 1 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &Y ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &XX );
}

void test_mbedtls_mpi_safe_cond_assign_wrapper( void ** params )
{

    test_mbedtls_mpi_safe_cond_assign( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3] );
}
#line 726 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_safe_cond_swap( int x_sign, char * x_str, int y_sign,
                                 char * y_str )
{
    mbedtls_mpi X, Y, XX, YY;

    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );
    mbedtls_mpi_init( &XX ); mbedtls_mpi_init( &YY );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, 16, x_str ) == 0 );
    X.s = x_sign;
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, 16, y_str ) == 0 );
    Y.s = y_sign;

    TEST_ASSERT( mbedtls_mpi_copy( &XX, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_copy( &YY, &Y ) == 0 );

    TEST_ASSERT( mbedtls_mpi_safe_cond_swap( &X, &Y, 0 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &XX ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Y, &YY ) == 0 );

    TEST_ASSERT( mbedtls_mpi_safe_cond_swap( &X, &Y, 1 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Y, &XX ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &YY ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
    mbedtls_mpi_free( &XX ); mbedtls_mpi_free( &YY );
}

void test_mbedtls_mpi_safe_cond_swap_wrapper( void ** params )
{

    test_mbedtls_mpi_safe_cond_swap( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3] );
}
#line 757 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_swap_sint( int input_X, int input_Y )
{
    mbedtls_mpi X, Y;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );

    TEST_ASSERT( mbedtls_mpi_lset( &X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_lset( &Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &Y, input_Y ) == 0 );

    mbedtls_mpi_swap( &X, &Y );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &X, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &Y, input_X ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
}

void test_mbedtls_mpi_swap_sint_wrapper( void ** params )
{

    test_mbedtls_mpi_swap_sint( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#line 777 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_swap_binary( data_t *input_X, data_t *input_Y )
{
    mbedtls_mpi X, Y, X0, Y0;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y );
    mbedtls_mpi_init( &X0 ); mbedtls_mpi_init( &Y0 );

    TEST_ASSERT( mbedtls_mpi_read_binary( &X, input_X->x, input_X->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_binary( &Y, input_Y->x, input_Y->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_binary( &X0, input_X->x, input_X->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_binary( &Y0, input_Y->x, input_Y->len ) == 0 );

    mbedtls_mpi_swap( &X, &Y );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &Y0 ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Y, &X0 ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y );
    mbedtls_mpi_free( &X0 ); mbedtls_mpi_free( &Y0 );
}

void test_mbedtls_mpi_swap_binary_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_mbedtls_mpi_swap_binary( &data0, &data2 );
}
#line 799 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_swap_self( data_t *input_X )
{
    mbedtls_mpi X, X0;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &X0 );

    TEST_ASSERT( mbedtls_mpi_read_binary( &X, input_X->x, input_X->len ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_binary( &X0, input_X->x, input_X->len ) == 0 );

    mbedtls_mpi_swap( &X, &X );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &X0 ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &X0 );
}

void test_mpi_swap_self_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};

    test_mpi_swap_self( &data0 );
}
#line 816 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_add_mpi( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi X, Y, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_mpi( &Z, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_add_mpi_wrapper( void ** params )
{

    test_mbedtls_mpi_add_mpi( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 834 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_add_mpi_inplace( int radix_X, char * input_X, int radix_A,
                                  char * input_A )
{
    mbedtls_mpi X, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_sub_abs( &X, &X, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_int( &X, 0 ) == 0 );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_abs( &X, &X, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &A ) == 0 );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_mpi( &X, &X, &X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_add_mpi_inplace_wrapper( void ** params )
{

    test_mbedtls_mpi_add_mpi_inplace( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3] );
}
#line 861 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_add_abs( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi X, Y, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_abs( &Z, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_add_abs_wrapper( void ** params )
{

    test_mbedtls_mpi_add_abs( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 879 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_add_abs_add_first( int radix_X, char * input_X, int radix_Y,
                            char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi X, Y, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_abs( &X, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &A );
}

void test_mpi_add_abs_add_first_wrapper( void ** params )
{

    test_mpi_add_abs_add_first( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 897 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_add_abs_add_second( int radix_X, char * input_X, int radix_Y,
                             char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi X, Y, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_abs( &Y, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Y, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &A );
}

void test_mpi_add_abs_add_second_wrapper( void ** params )
{

    test_mpi_add_abs_add_second( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 915 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_add_int( int radix_X, char * input_X, int input_Y,
                          int radix_A, char * input_A )
{
    mbedtls_mpi X, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_add_int( &Z, &X, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_add_int_wrapper( void ** params )
{

    test_mbedtls_mpi_add_int( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4] );
}
#line 932 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_sub_mpi( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi X, Y, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_sub_mpi( &Z, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_sub_mpi_wrapper( void ** params )
{

    test_mbedtls_mpi_sub_mpi( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 950 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_sub_abs( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A,
                          int sub_result )
{
    mbedtls_mpi X, Y, Z, A;
    int res;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );

    res = mbedtls_mpi_sub_abs( &Z, &X, &Y );
    TEST_ASSERT( res == sub_result );
    if( res == 0 )
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_sub_abs_wrapper( void ** params )
{

    test_mbedtls_mpi_sub_abs( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ) );
}
#line 973 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_sub_int( int radix_X, char * input_X, int input_Y,
                          int radix_A, char * input_A )
{
    mbedtls_mpi X, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_sub_int( &Z, &X, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_sub_int_wrapper( void ** params )
{

    test_mbedtls_mpi_sub_int( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4] );
}
#line 990 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_mul_mpi( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A )
{
    mbedtls_mpi X, Y, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_mul_mpi( &Z, &X, &Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_mul_mpi_wrapper( void ** params )
{

    test_mbedtls_mpi_mul_mpi( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5] );
}
#line 1008 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_mul_int( int radix_X, char * input_X, int input_Y,
                          int radix_A, char * input_A,
                          char * result_comparison )
{
    mbedtls_mpi X, Z, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_mul_int( &Z, &X, input_Y ) == 0 );
    if( strcmp( result_comparison, "==" ) == 0 )
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );
    else if( strcmp( result_comparison, "!=" ) == 0 )
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) != 0 );
    else
        TEST_ASSERT( "unknown operator" == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_mul_int_wrapper( void ** params )
{

    test_mbedtls_mpi_mul_int( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4], (char *) params[5] );
}
#line 1031 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_div_mpi( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A,
                          int radix_B, char * input_B, int div_result )
{
    mbedtls_mpi X, Y, Q, R, A, B;
    int res;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Q ); mbedtls_mpi_init( &R );
    mbedtls_mpi_init( &A ); mbedtls_mpi_init( &B );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &B, radix_B, input_B ) == 0 );
    res = mbedtls_mpi_div_mpi( &Q, &R, &X, &Y );
    TEST_ASSERT( res == div_result );
    if( res == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Q, &A ) == 0 );
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &R, &B ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Q ); mbedtls_mpi_free( &R );
    mbedtls_mpi_free( &A ); mbedtls_mpi_free( &B );
}

void test_mbedtls_mpi_div_mpi_wrapper( void ** params )
{

    test_mbedtls_mpi_div_mpi( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ) );
}
#line 1059 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_div_int( int radix_X, char * input_X, int input_Y,
                          int radix_A, char * input_A, int radix_B,
                          char * input_B, int div_result )
{
    mbedtls_mpi X, Q, R, A, B;
    int res;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Q ); mbedtls_mpi_init( &R ); mbedtls_mpi_init( &A );
    mbedtls_mpi_init( &B );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &B, radix_B, input_B ) == 0 );
    res = mbedtls_mpi_div_int( &Q, &R, &X, input_Y );
    TEST_ASSERT( res == div_result );
    if( res == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Q, &A ) == 0 );
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &R, &B ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Q ); mbedtls_mpi_free( &R ); mbedtls_mpi_free( &A );
    mbedtls_mpi_free( &B );
}

void test_mbedtls_mpi_div_int_wrapper( void ** params )
{

    test_mbedtls_mpi_div_int( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4], *( (int *) params[5] ), (char *) params[6], *( (int *) params[7] ) );
}
#line 1086 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_mod_mpi( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A,
                          int div_result )
{
    mbedtls_mpi X, Y, A;
    int res;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    res = mbedtls_mpi_mod_mpi( &X, &X, &Y );
    TEST_ASSERT( res == div_result );
    if( res == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &A ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_mod_mpi_wrapper( void ** params )
{

    test_mbedtls_mpi_mod_mpi( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ) );
}
#line 1110 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_mod_int( int radix_X, char * input_X, int input_Y,
                          int input_A, int div_result )
{
    mbedtls_mpi X;
    int res;
    mbedtls_mpi_uint r;
    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    res = mbedtls_mpi_mod_int( &r, &X, input_Y );
    TEST_ASSERT( res == div_result );
    if( res == 0 )
    {
        TEST_ASSERT( r == (mbedtls_mpi_uint) input_A );
    }

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_mod_int_wrapper( void ** params )
{

    test_mbedtls_mpi_mod_int( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#line 1132 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_exp_mod( int radix_A, char * input_A, int radix_E,
                          char * input_E, int radix_N, char * input_N,
                          int radix_RR, char * input_RR, int radix_X,
                          char * input_X, int div_result )
{
    mbedtls_mpi A, E, N, RR, Z, X;
    int res;
    mbedtls_mpi_init( &A  ); mbedtls_mpi_init( &E ); mbedtls_mpi_init( &N );
    mbedtls_mpi_init( &RR ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &E, radix_E, input_E ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &N, radix_N, input_N ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );

    if( strlen( input_RR ) )
        TEST_ASSERT( mbedtls_mpi_read_string( &RR, radix_RR, input_RR ) == 0 );

    res = mbedtls_mpi_exp_mod( &Z, &A, &E, &N, &RR );
    TEST_ASSERT( res == div_result );
    if( res == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &X ) == 0 );
    }

exit:
    mbedtls_mpi_free( &A  ); mbedtls_mpi_free( &E ); mbedtls_mpi_free( &N );
    mbedtls_mpi_free( &RR ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_exp_mod_wrapper( void ** params )
{

    test_mbedtls_mpi_exp_mod( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ), (char *) params[7], *( (int *) params[8] ), (char *) params[9], *( (int *) params[10] ) );
}
#line 1164 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_inv_mod( int radix_X, char * input_X, int radix_Y,
                          char * input_Y, int radix_A, char * input_A,
                          int div_result )
{
    mbedtls_mpi X, Y, Z, A;
    int res;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &Y ); mbedtls_mpi_init( &Z ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &Y, radix_Y, input_Y ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    res = mbedtls_mpi_inv_mod( &Z, &X, &Y );
    TEST_ASSERT( res == div_result );
    if( res == 0 )
    {
        TEST_ASSERT( mbedtls_mpi_cmp_mpi( &Z, &A ) == 0 );
    }

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &Y ); mbedtls_mpi_free( &Z ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_inv_mod_wrapper( void ** params )
{

    test_mbedtls_mpi_inv_mod( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), (char *) params[3], *( (int *) params[4] ), (char *) params[5], *( (int *) params[6] ) );
}
#if defined(MBEDTLS_GENPRIME)
#line 1188 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_is_prime( int radix_X, char * input_X, int div_result )
{
    mbedtls_mpi X;
    int res;
    mbedtls_mpi_init( &X );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    res = mbedtls_mpi_is_prime_ext( &X, 40, rnd_std_rand, NULL );
    TEST_ASSERT( res == div_result );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_is_prime_wrapper( void ** params )
{

    test_mbedtls_mpi_is_prime( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ) );
}
#endif /* MBEDTLS_GENPRIME */
#if defined(MBEDTLS_GENPRIME)
#line 1204 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_is_prime_det( data_t * input_X, data_t * witnesses,
                               int chunk_len, int rounds )
{
    mbedtls_mpi X;
    int res;
    mbedtls_test_mpi_random rand;

    mbedtls_mpi_init( &X );
    rand.data = witnesses;
    rand.pos = 0;
    rand.chunk_len = chunk_len;

    TEST_ASSERT( mbedtls_mpi_read_binary( &X, input_X->x, input_X->len ) == 0 );
    res = mbedtls_mpi_is_prime_ext( &X, rounds - 1,
                                    mbedtls_test_mpi_miller_rabin_determinizer,
                                    &rand );
    TEST_ASSERT( res == 0 );

    rand.data = witnesses;
    rand.pos = 0;
    rand.chunk_len = chunk_len;

    res = mbedtls_mpi_is_prime_ext( &X, rounds,
                                    mbedtls_test_mpi_miller_rabin_determinizer,
                                    &rand );
    TEST_ASSERT( res == MBEDTLS_ERR_MPI_NOT_ACCEPTABLE );

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_is_prime_det_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_mbedtls_mpi_is_prime_det( &data0, &data2, *( (int *) params[4] ), *( (int *) params[5] ) );
}
#endif /* MBEDTLS_GENPRIME */
#if defined(MBEDTLS_GENPRIME)
#line 1237 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_gen_prime( int bits, int flags, int ref_ret )
{
    mbedtls_mpi X;
    int my_ret;

    mbedtls_mpi_init( &X );

    my_ret = mbedtls_mpi_gen_prime( &X, bits, flags, rnd_std_rand, NULL );
    TEST_ASSERT( my_ret == ref_ret );

    if( ref_ret == 0 )
    {
        size_t actual_bits = mbedtls_mpi_bitlen( &X );

        TEST_ASSERT( actual_bits >= (size_t) bits );
        TEST_ASSERT( actual_bits <= (size_t) bits + 1 );

        TEST_ASSERT( mbedtls_mpi_is_prime_ext( &X, 40, rnd_std_rand, NULL )
                     == 0 );
        if( flags & MBEDTLS_MPI_GEN_PRIME_FLAG_DH )
        {
            /* X = ( X - 1 ) / 2 */
            TEST_ASSERT( mbedtls_mpi_shift_r( &X, 1 ) == 0 );
            TEST_ASSERT( mbedtls_mpi_is_prime_ext( &X, 40, rnd_std_rand, NULL )
                         == 0 );
        }
    }

exit:
    mbedtls_mpi_free( &X );
}

void test_mbedtls_mpi_gen_prime_wrapper( void ** params )
{

    test_mbedtls_mpi_gen_prime( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* MBEDTLS_GENPRIME */
#line 1271 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_shift_l( int radix_X, char * input_X, int shift_X,
                          int radix_A, char * input_A )
{
    mbedtls_mpi X, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_shift_l( &X, shift_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_shift_l_wrapper( void ** params )
{

    test_mbedtls_mpi_shift_l( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4] );
}
#line 1288 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mbedtls_mpi_shift_r( int radix_X, char * input_X, int shift_X,
                          int radix_A, char * input_A )
{
    mbedtls_mpi X, A;
    mbedtls_mpi_init( &X ); mbedtls_mpi_init( &A );

    TEST_ASSERT( mbedtls_mpi_read_string( &X, radix_X, input_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_read_string( &A, radix_A, input_A ) == 0 );
    TEST_ASSERT( mbedtls_mpi_shift_r( &X, shift_X ) == 0 );
    TEST_ASSERT( mbedtls_mpi_cmp_mpi( &X, &A ) == 0 );

exit:
    mbedtls_mpi_free( &X ); mbedtls_mpi_free( &A );
}

void test_mbedtls_mpi_shift_r_wrapper( void ** params )
{

    test_mbedtls_mpi_shift_r( *( (int *) params[0] ), (char *) params[1], *( (int *) params[2] ), *( (int *) params[3] ), (char *) params[4] );
}
#if defined(MBEDTLS_SELF_TEST)
#line 1305 "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_mpi.function"
void test_mpi_selftest(  )
{
    TEST_ASSERT( mbedtls_mpi_self_test( 1 ) == 0 );
exit:
    ;
}

void test_mpi_selftest_wrapper( void ** params )
{
    (void)params;

    test_mpi_selftest(  );
}
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_BIGNUM_C */


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

#if defined(MBEDTLS_BIGNUM_C)

        case 0:
            {
                *out_value = MBEDTLS_ERR_MPI_INVALID_CHARACTER;
            }
            break;
        case 1:
            {
                *out_value = MBEDTLS_ERR_MPI_BAD_INPUT_DATA;
            }
            break;
        case 2:
            {
                *out_value = MBEDTLS_ERR_MPI_BUFFER_TOO_SMALL;
            }
            break;
        case 3:
            {
                *out_value = MBEDTLS_ERR_MPI_FILE_IO_ERROR;
            }
            break;
        case 4:
            {
                *out_value = -1;
            }
            break;
        case 5:
            {
                *out_value = -2;
            }
            break;
        case 6:
            {
                *out_value = -3;
            }
            break;
        case 7:
            {
                *out_value = -1500;
            }
            break;
        case 8:
            {
                *out_value = -42;
            }
            break;
        case 9:
            {
                *out_value = +1;
            }
            break;
        case 10:
            {
                *out_value = -9871232;
            }
            break;
        case 11:
            {
                *out_value = MBEDTLS_ERR_MPI_NEGATIVE_VALUE;
            }
            break;
        case 12:
            {
                *out_value = MBEDTLS_ERR_MPI_DIVISION_BY_ZERO;
            }
            break;
        case 13:
            {
                *out_value = -13;
            }
            break;
        case 14:
            {
                *out_value = -34;
            }
            break;
        case 15:
            {
                *out_value = MBEDTLS_ERR_MPI_NOT_ACCEPTABLE;
            }
            break;
        case 16:
            {
                *out_value = MBEDTLS_MPI_GEN_PRIME_FLAG_DH;
            }
            break;
        case 17:
            {
                *out_value = MBEDTLS_MPI_GEN_PRIME_FLAG_DH | MBEDTLS_MPI_GEN_PRIME_FLAG_LOW_ERR;
            }
            break;
        case 18:
            {
                *out_value = MBEDTLS_MPI_GEN_PRIME_FLAG_LOW_ERR;
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

#if defined(MBEDTLS_BIGNUM_C)

        case 0:
            {
#if defined(MBEDTLS_GENPRIME)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
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

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_valid_param_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_CHECK_PARAMS) && !defined(MBEDTLS_PARAM_FAILED_ALT)
    test_mpi_invalid_param_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_null_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_read_write_string_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_read_binary_wrapper,
#else
    NULL,
#endif
/* Function Id: 5 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_read_binary_le_wrapper,
#else
    NULL,
#endif
/* Function Id: 6 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_write_binary_wrapper,
#else
    NULL,
#endif
/* Function Id: 7 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_write_binary_le_wrapper,
#else
    NULL,
#endif
/* Function Id: 8 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_FS_IO)
    test_mbedtls_mpi_read_file_wrapper,
#else
    NULL,
#endif
/* Function Id: 9 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_FS_IO)
    test_mbedtls_mpi_write_file_wrapper,
#else
    NULL,
#endif
/* Function Id: 10 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_get_bit_wrapper,
#else
    NULL,
#endif
/* Function Id: 11 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_set_bit_wrapper,
#else
    NULL,
#endif
/* Function Id: 12 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_lsb_wrapper,
#else
    NULL,
#endif
/* Function Id: 13 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_bitlen_wrapper,
#else
    NULL,
#endif
/* Function Id: 14 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_gcd_wrapper,
#else
    NULL,
#endif
/* Function Id: 15 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_cmp_int_wrapper,
#else
    NULL,
#endif
/* Function Id: 16 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_cmp_mpi_wrapper,
#else
    NULL,
#endif
/* Function Id: 17 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_lt_mpi_ct_wrapper,
#else
    NULL,
#endif
/* Function Id: 18 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_cmp_abs_wrapper,
#else
    NULL,
#endif
/* Function Id: 19 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_copy_sint_wrapper,
#else
    NULL,
#endif
/* Function Id: 20 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_copy_binary_wrapper,
#else
    NULL,
#endif
/* Function Id: 21 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_copy_self_wrapper,
#else
    NULL,
#endif
/* Function Id: 22 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_shrink_wrapper,
#else
    NULL,
#endif
/* Function Id: 23 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_safe_cond_assign_wrapper,
#else
    NULL,
#endif
/* Function Id: 24 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_safe_cond_swap_wrapper,
#else
    NULL,
#endif
/* Function Id: 25 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_swap_sint_wrapper,
#else
    NULL,
#endif
/* Function Id: 26 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_swap_binary_wrapper,
#else
    NULL,
#endif
/* Function Id: 27 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_swap_self_wrapper,
#else
    NULL,
#endif
/* Function Id: 28 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_add_mpi_wrapper,
#else
    NULL,
#endif
/* Function Id: 29 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_add_mpi_inplace_wrapper,
#else
    NULL,
#endif
/* Function Id: 30 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_add_abs_wrapper,
#else
    NULL,
#endif
/* Function Id: 31 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_add_abs_add_first_wrapper,
#else
    NULL,
#endif
/* Function Id: 32 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mpi_add_abs_add_second_wrapper,
#else
    NULL,
#endif
/* Function Id: 33 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_add_int_wrapper,
#else
    NULL,
#endif
/* Function Id: 34 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_sub_mpi_wrapper,
#else
    NULL,
#endif
/* Function Id: 35 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_sub_abs_wrapper,
#else
    NULL,
#endif
/* Function Id: 36 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_sub_int_wrapper,
#else
    NULL,
#endif
/* Function Id: 37 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_mul_mpi_wrapper,
#else
    NULL,
#endif
/* Function Id: 38 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_mul_int_wrapper,
#else
    NULL,
#endif
/* Function Id: 39 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_div_mpi_wrapper,
#else
    NULL,
#endif
/* Function Id: 40 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_div_int_wrapper,
#else
    NULL,
#endif
/* Function Id: 41 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_mod_mpi_wrapper,
#else
    NULL,
#endif
/* Function Id: 42 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_mod_int_wrapper,
#else
    NULL,
#endif
/* Function Id: 43 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_exp_mod_wrapper,
#else
    NULL,
#endif
/* Function Id: 44 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_inv_mod_wrapper,
#else
    NULL,
#endif
/* Function Id: 45 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_mpi_is_prime_wrapper,
#else
    NULL,
#endif
/* Function Id: 46 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_mpi_is_prime_det_wrapper,
#else
    NULL,
#endif
/* Function Id: 47 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_GENPRIME)
    test_mbedtls_mpi_gen_prime_wrapper,
#else
    NULL,
#endif
/* Function Id: 48 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_shift_l_wrapper,
#else
    NULL,
#endif
/* Function Id: 49 */

#if defined(MBEDTLS_BIGNUM_C)
    test_mbedtls_mpi_shift_r_wrapper,
#else
    NULL,
#endif
/* Function Id: 50 */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_SELF_TEST)
    test_mpi_selftest_wrapper,
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
    const char *default_filename = "./test_suite_mpi.datax";
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
