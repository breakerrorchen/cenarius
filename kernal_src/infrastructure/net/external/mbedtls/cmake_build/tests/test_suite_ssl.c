#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_ssl.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/main_test.function
 *      Platform code file  : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/host_test.function
 *      Helper file         : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/helpers.function
 *      Test suite file     : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function
 *      Test suite data     : /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.data
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


#line 38 "suites/main_test.function"


/*----------------------------------------------------------------------------*/
/* Test Suite Code */


#define TEST_SUITE_ACTIVE

#if defined(MBEDTLS_SSL_TLS_C)
#line 2 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
#include <mbedtls/ssl.h>
#include <mbedtls/ssl_internal.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/certs.h>
#include <mbedtls/timing.h>
#include <mbedtls/debug.h>

typedef struct log_pattern
{
    const char *pattern;
    size_t counter;
} log_pattern;

/* This function can be passed to mbedtls to receive output logs from it. In
 * this case, it will count the instances of a log_pattern in the received
 * logged messages.
 */
void log_analyzer( void *ctx, int level,
                   const char *file, int line,
                   const char *str )
{
    log_pattern *p = (log_pattern *) ctx;

    (void) level;
    (void) line;
    (void) file;

    if( NULL != p &&
        NULL != p->pattern &&
        NULL != strstr( str, p->pattern ) )
    {
        p->counter++;
    }
}

typedef struct handshake_test_options
{
    const char *cipher;
    int version;
    int pk_alg;
    data_t *psk_str;
    int dtls;
    int srv_auth_mode;
    int serialize;
    int mfl;
    int cli_msg_len;
    int srv_msg_len;
    int expected_cli_fragments;
    int expected_srv_fragments;
    int renegotiate;
    int legacy_renegotiation;
    void *srv_log_obj;
    void *cli_log_obj;
    void (*srv_log_fun)(void *, int, const char *, int, const char *);
    void (*cli_log_fun)(void *, int, const char *, int, const char *);
} handshake_test_options;

void init_handshake_options( handshake_test_options *opts )
{
  opts->cipher = "";
  opts->version = MBEDTLS_SSL_MINOR_VERSION_3;
  opts->pk_alg = MBEDTLS_PK_RSA;
  opts->psk_str = NULL;
  opts->dtls = 0;
  opts->srv_auth_mode = MBEDTLS_SSL_VERIFY_NONE;
  opts->serialize = 0;
  opts->mfl = MBEDTLS_SSL_MAX_FRAG_LEN_NONE;
  opts->cli_msg_len = 100;
  opts->srv_msg_len = 100;
  opts->expected_cli_fragments = 1;
  opts->expected_srv_fragments = 1;
  opts->renegotiate = 0;
  opts->legacy_renegotiation = MBEDTLS_SSL_LEGACY_NO_RENEGOTIATION;
  opts->srv_log_obj = NULL;
  opts->srv_log_obj = NULL;
  opts->srv_log_fun = NULL;
  opts->cli_log_fun = NULL;
}
/*
 * Buffer structure for custom I/O callbacks.
 */

typedef struct mbedtls_test_buffer
{
    size_t start;
    size_t content_length;
    size_t capacity;
    unsigned char *buffer;
} mbedtls_test_buffer;

/*
 * Initialises \p buf. After calling this function it is safe to call
 * `mbedtls_test_buffer_free()` on \p buf.
 */
void mbedtls_test_buffer_init( mbedtls_test_buffer *buf )
{
    memset( buf, 0, sizeof( *buf ) );
}

/*
 * Sets up \p buf. After calling this function it is safe to call
 * `mbedtls_test_buffer_put()` and `mbedtls_test_buffer_get()` on \p buf.
 */
int mbedtls_test_buffer_setup( mbedtls_test_buffer *buf, size_t capacity )
{
    buf->buffer = (unsigned char*) mbedtls_calloc( capacity,
                                                   sizeof(unsigned char) );
    if( NULL == buf->buffer )
        return MBEDTLS_ERR_SSL_ALLOC_FAILED;
    buf->capacity = capacity;

    return 0;
}

void mbedtls_test_buffer_free( mbedtls_test_buffer *buf )
{
    if( buf->buffer != NULL )
        mbedtls_free( buf->buffer );

    memset( buf, 0, sizeof( *buf ) );
}

/*
 * Puts \p input_len bytes from the \p input buffer into the ring buffer \p buf.
 *
 * \p buf must have been initialized and set up by calling
 * `mbedtls_test_buffer_init()` and `mbedtls_test_buffer_setup()`.
 *
 * \retval  \p input_len, if the data fits.
 * \retval  0 <= value < \p input_len, if the data does not fit.
 * \retval  -1, if \p buf is NULL, it hasn't been set up or \p input_len is not
 *          zero and \p input is NULL.
 */
int mbedtls_test_buffer_put( mbedtls_test_buffer *buf,
                             const unsigned char *input, size_t input_len )
{
    size_t overflow = 0;

    if( ( buf == NULL ) || ( buf->buffer == NULL ) )
        return -1;

    /* Reduce input_len to a number that fits in the buffer. */
    if ( ( buf->content_length + input_len ) > buf->capacity )
    {
        input_len = buf->capacity - buf->content_length;
    }

    if( input == NULL )
    {
        return ( input_len == 0 ) ? 0 : -1;
    }

     /* Check if the buffer has not come full circle and free space is not in
      * the middle */
    if( buf->start + buf->content_length < buf->capacity )
    {

        /* Calculate the number of bytes that need to be placed at lower memory
        * address */
        if( buf->start + buf->content_length + input_len
            > buf->capacity )
        {
            overflow = ( buf->start + buf->content_length + input_len )
                        % buf->capacity;
        }

        memcpy( buf->buffer + buf->start + buf->content_length, input,
                    input_len - overflow );
        memcpy( buf->buffer, input + input_len - overflow, overflow );

    }
    else
    {
        /* The buffer has come full circle and free space is in the middle */
        memcpy( buf->buffer + buf->start + buf->content_length - buf->capacity,
                input, input_len );
    }

    buf->content_length += input_len;
    return input_len;
}

/*
 * Gets \p output_len bytes from the ring buffer \p buf into the
 * \p output buffer. The output buffer can be NULL, in this case a part of the
 * ring buffer will be dropped, if the requested length is available.
 *
 * \p buf must have been initialized and set up by calling
 * `mbedtls_test_buffer_init()` and `mbedtls_test_buffer_setup()`.
 *
 * \retval  \p output_len, if the data is available.
 * \retval  0 <= value < \p output_len, if the data is not available.
 * \retval  -1, if \buf is NULL or it hasn't been set up.
 */
int mbedtls_test_buffer_get( mbedtls_test_buffer *buf,
                             unsigned char* output, size_t output_len )
{
    size_t overflow = 0;

    if( ( buf == NULL ) || ( buf->buffer == NULL ) )
        return -1;

    if( output == NULL && output_len == 0 )
        return 0;

    if( buf->content_length < output_len )
        output_len = buf->content_length;

    /* Calculate the number of bytes that need to be drawn from lower memory
     * address */
    if( buf->start + output_len > buf->capacity )
    {
        overflow = ( buf->start + output_len ) % buf->capacity;
    }

    if( output != NULL )
    {
        memcpy( output, buf->buffer + buf->start, output_len - overflow );
        memcpy( output + output_len - overflow, buf->buffer, overflow );
    }

    buf->content_length -= output_len;
    buf->start = ( buf->start + output_len ) % buf->capacity;

    return output_len;
}

/*
 * Errors used in the message transport mock tests
 */
 #define MBEDTLS_TEST_ERROR_ARG_NULL -11
 #define MBEDTLS_TEST_ERROR_MESSAGE_TRUNCATED -44

/*
 * Context for a message metadata queue (fifo) that is on top of the ring buffer.
 */
typedef struct mbedtls_test_message_queue
{
    size_t *messages;
    int pos;
    int num;
    int capacity;
} mbedtls_test_message_queue;

/*
 * Setup and free functions for the message metadata queue.
 *
 * \p capacity describes the number of message metadata chunks that can be held
 *    within the queue.
 *
 * \retval  0, if a metadata queue of a given length can be allocated.
 * \retval  MBEDTLS_ERR_SSL_ALLOC_FAILED, if allocation failed.
 */
int mbedtls_test_message_queue_setup( mbedtls_test_message_queue *queue,
                                      size_t capacity )
{
    queue->messages = (size_t*) mbedtls_calloc( capacity, sizeof(size_t) );
    if( NULL == queue->messages )
        return MBEDTLS_ERR_SSL_ALLOC_FAILED;

    queue->capacity = capacity;
    queue->pos = 0;
    queue->num = 0;

    return 0;
}

void mbedtls_test_message_queue_free( mbedtls_test_message_queue *queue )
{
    if( queue == NULL )
        return;

    if( queue->messages != NULL )
        mbedtls_free( queue->messages );

    memset( queue, 0, sizeof( *queue ) );
}

/*
 * Push message length information onto the message metadata queue.
 * This will become the last element to leave it (fifo).
 *
 * \retval  MBEDTLS_TEST_ERROR_ARG_NULL, if the queue is null.
 * \retval  MBEDTLS_ERR_SSL_WANT_WRITE, if the queue is full.
 * \retval  \p len, if the push was successful.
 */
int mbedtls_test_message_queue_push_info( mbedtls_test_message_queue *queue,
                                          size_t len )
{
    int place;
    if( queue == NULL )
        return MBEDTLS_TEST_ERROR_ARG_NULL;

    if( queue->num >= queue->capacity )
        return MBEDTLS_ERR_SSL_WANT_WRITE;

    place = ( queue->pos + queue->num ) % queue->capacity;
    queue->messages[place] = len;
    queue->num++;
    return len;
}

/*
 * Pop information about the next message length from the queue. This will be
 * the oldest inserted message length(fifo). \p msg_len can be null, in which
 * case the data will be popped from the queue but not copied anywhere.
 *
 * \retval  MBEDTLS_TEST_ERROR_ARG_NULL, if the queue is null.
 * \retval  MBEDTLS_ERR_SSL_WANT_READ, if the queue is empty.
 * \retval  message length, if the pop was successful, up to the given
            \p buf_len.
 */
int mbedtls_test_message_queue_pop_info( mbedtls_test_message_queue *queue,
                                         size_t buf_len )
{
    size_t message_length;
    if( queue == NULL )
        return MBEDTLS_TEST_ERROR_ARG_NULL;
    if( queue->num == 0 )
        return MBEDTLS_ERR_SSL_WANT_READ;

    message_length = queue->messages[queue->pos];
    queue->messages[queue->pos] = 0;
    queue->num--;
    queue->pos++;
    queue->pos %= queue->capacity;
    if( queue->pos < 0 )
        queue->pos += queue->capacity;

    return ( message_length > buf_len ) ? buf_len : message_length;
}

/*
 * Take a peek on the info about the next message length from the queue.
 * This will be the oldest inserted message length(fifo).
 *
 * \retval  MBEDTLS_TEST_ERROR_ARG_NULL, if the queue is null.
 * \retval  MBEDTLS_ERR_SSL_WANT_READ, if the queue is empty.
 * \retval  0, if the peek was successful.
 * \retval  MBEDTLS_TEST_ERROR_MESSAGE_TRUNCATED, if the given buffer length is
 *          too small to fit the message. In this case the \p msg_len will be
 *          set to the full message length so that the
 *          caller knows what portion of the message can be dropped.
 */
int mbedtls_test_message_queue_peek_info( mbedtls_test_message_queue *queue,
                                          size_t buf_len, size_t* msg_len )
{
    if( queue == NULL || msg_len == NULL )
        return MBEDTLS_TEST_ERROR_ARG_NULL;
    if( queue->num == 0 )
        return MBEDTLS_ERR_SSL_WANT_READ;

    *msg_len = queue->messages[queue->pos];
    return ( *msg_len > buf_len ) ? MBEDTLS_TEST_ERROR_MESSAGE_TRUNCATED : 0;
}
/*
 * Context for the I/O callbacks simulating network connection.
 */

#define MBEDTLS_MOCK_SOCKET_CONNECTED 1

typedef struct mbedtls_mock_socket
{
    int status;
    mbedtls_test_buffer *input;
    mbedtls_test_buffer *output;
    struct mbedtls_mock_socket *peer;
} mbedtls_mock_socket;

/*
 * Setup and teardown functions for mock sockets.
 */
void mbedtls_mock_socket_init( mbedtls_mock_socket *socket )
{
    memset( socket, 0, sizeof( *socket ) );
}

/*
 * Closes the socket \p socket.
 *
 * \p socket must have been previously initialized by calling
 * mbedtls_mock_socket_init().
 *
 * This function frees all allocated resources and both sockets are aware of the
 * new connection state.
 *
 * That is, this function does not simulate half-open TCP connections and the
 * phenomenon that when closing a UDP connection the peer is not aware of the
 * connection having been closed.
 */
void mbedtls_mock_socket_close( mbedtls_mock_socket* socket )
{
    if( socket == NULL )
        return;

    if( socket->input != NULL )
    {
        mbedtls_test_buffer_free( socket->input );
        mbedtls_free( socket->input );
    }

    if( socket->output != NULL )
    {
        mbedtls_test_buffer_free( socket->output );
        mbedtls_free( socket->output );
    }

    if( socket->peer != NULL )
        memset( socket->peer, 0, sizeof( *socket->peer ) );

    memset( socket, 0, sizeof( *socket ) );
}

/*
 * Establishes a connection between \p peer1 and \p peer2.
 *
 * \p peer1 and \p peer2 must have been previously initialized by calling
 * mbedtls_mock_socket_init().
 *
 * The capacites of the internal buffers are set to \p bufsize. Setting this to
 * the correct value allows for simulation of MTU, sanity testing the mock
 * implementation and mocking TCP connections with lower memory cost.
 */
int mbedtls_mock_socket_connect( mbedtls_mock_socket* peer1,
                                 mbedtls_mock_socket* peer2,
                                 size_t bufsize )
{
    int ret = -1;

    peer1->output =
        (mbedtls_test_buffer*) mbedtls_calloc( 1, sizeof(mbedtls_test_buffer) );
    if( peer1->output == NULL )
    {
        ret = MBEDTLS_ERR_SSL_ALLOC_FAILED;
        goto exit;
    }
    mbedtls_test_buffer_init( peer1->output );
    if( 0 != ( ret = mbedtls_test_buffer_setup( peer1->output, bufsize ) ) )
    {
        goto exit;
    }

    peer2->output =
        (mbedtls_test_buffer*) mbedtls_calloc( 1, sizeof(mbedtls_test_buffer) );
    if( peer2->output == NULL )
    {
        ret = MBEDTLS_ERR_SSL_ALLOC_FAILED;
        goto exit;
    }
    mbedtls_test_buffer_init( peer2->output );
    if( 0 != ( ret = mbedtls_test_buffer_setup( peer2->output, bufsize ) ) )
    {
        goto exit;
    }

    peer1->peer = peer2;
    peer2->peer = peer1;
    peer1->input = peer2->output;
    peer2->input = peer1->output;

    peer1->status = peer2->status = MBEDTLS_MOCK_SOCKET_CONNECTED;
    ret = 0;

exit:

    if( ret != 0 )
    {
        mbedtls_mock_socket_close( peer1 );
        mbedtls_mock_socket_close( peer2 );
    }

    return ret;
}

/*
 * Callbacks for simulating blocking I/O over connection-oriented transport.
 */

int mbedtls_mock_tcp_send_b( void *ctx, const unsigned char *buf, size_t len )
{
    mbedtls_mock_socket *socket = (mbedtls_mock_socket*) ctx;

    if( socket == NULL || socket->status != MBEDTLS_MOCK_SOCKET_CONNECTED )
        return -1;

    return mbedtls_test_buffer_put( socket->output, buf, len );
}

int mbedtls_mock_tcp_recv_b( void *ctx, unsigned char *buf, size_t len )
{
    mbedtls_mock_socket *socket = (mbedtls_mock_socket*) ctx;

    if( socket == NULL || socket->status != MBEDTLS_MOCK_SOCKET_CONNECTED )
        return -1;

    return mbedtls_test_buffer_get( socket->input, buf, len );
}

/*
 * Callbacks for simulating non-blocking I/O over connection-oriented transport.
 */

int mbedtls_mock_tcp_send_nb( void *ctx, const unsigned char *buf, size_t len )
{
    mbedtls_mock_socket *socket = (mbedtls_mock_socket*) ctx;

    if( socket == NULL || socket->status != MBEDTLS_MOCK_SOCKET_CONNECTED )
        return -1;

    if( socket->output->capacity == socket->output->content_length )
    {
        return MBEDTLS_ERR_SSL_WANT_WRITE;
    }

    return mbedtls_test_buffer_put( socket->output, buf, len );
}

int mbedtls_mock_tcp_recv_nb( void *ctx, unsigned char *buf, size_t len )
{
    mbedtls_mock_socket *socket = (mbedtls_mock_socket*) ctx;

    if( socket == NULL || socket->status != MBEDTLS_MOCK_SOCKET_CONNECTED )
        return -1;

    if( socket->input->content_length == 0 )
    {
        return MBEDTLS_ERR_SSL_WANT_READ;
    }

    return mbedtls_test_buffer_get( socket->input, buf, len );
}

/* Errors used in the message socket mocks */

#define MBEDTLS_TEST_ERROR_CONTEXT_ERROR -55
#define MBEDTLS_TEST_ERROR_SEND_FAILED -66
#define MBEDTLS_TEST_ERROR_RECV_FAILED -77

/*
 * Structure used as an addon, or a wrapper, around the mocked sockets.
 * Contains an input queue, to which the other socket pushes metadata,
 * and an output queue, to which this one pushes metadata. This context is
 * considered as an owner of the input queue only, which is initialized and
 * freed in the respective setup and free calls.
 */
typedef struct mbedtls_test_message_socket_context
{
    mbedtls_test_message_queue* queue_input;
    mbedtls_test_message_queue* queue_output;
    mbedtls_mock_socket* socket;
} mbedtls_test_message_socket_context;

/*
 * Setup a given mesasge socket context including initialization of
 * input/output queues to a chosen capacity of messages. Also set the
 * corresponding mock socket.
 *
 * \retval  0, if everything succeeds.
 * \retval  MBEDTLS_ERR_SSL_ALLOC_FAILED, if allocation of a message
 *          queue failed.
 */
int mbedtls_message_socket_setup( mbedtls_test_message_queue* queue_input,
                                  mbedtls_test_message_queue* queue_output,
                                  size_t queue_capacity,
                                  mbedtls_mock_socket* socket,
                                  mbedtls_test_message_socket_context* ctx )
{
    int ret = mbedtls_test_message_queue_setup( queue_input, queue_capacity );
    if( ret != 0 )
        return ret;
    ctx->queue_input = queue_input;
    ctx->queue_output = queue_output;
    ctx->socket = socket;
    mbedtls_mock_socket_init( socket );

    return 0;
}

/*
 * Close a given message socket context, along with the socket itself. Free the
 * memory allocated by the input queue.
 */
void mbedtls_message_socket_close( mbedtls_test_message_socket_context* ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_test_message_queue_free( ctx->queue_input );
    mbedtls_mock_socket_close( ctx->socket );
    memset( ctx, 0, sizeof( *ctx ) );
}

/*
 * Send one message through a given message socket context.
 *
 * \retval  \p len, if everything succeeds.
 * \retval  MBEDTLS_TEST_ERROR_CONTEXT_ERROR, if any of the needed context
 *          elements or the context itself is null.
 * \retval  MBEDTLS_TEST_ERROR_SEND_FAILED if mbedtls_mock_tcp_send_b failed.
 * \retval  MBEDTLS_ERR_SSL_WANT_WRITE, if the output queue is full.
 *
 * This function will also return any error from
 * mbedtls_test_message_queue_push_info.
 */
int mbedtls_mock_tcp_send_msg( void *ctx, const unsigned char *buf, size_t len )
{
    mbedtls_test_message_queue* queue;
    mbedtls_mock_socket* socket;
    mbedtls_test_message_socket_context *context = (mbedtls_test_message_socket_context*) ctx;

    if( context == NULL || context->socket == NULL
        || context->queue_output == NULL )
    {
        return MBEDTLS_TEST_ERROR_CONTEXT_ERROR;
    }

    queue = context->queue_output;
    socket = context->socket;

    if( queue->num >= queue->capacity )
        return MBEDTLS_ERR_SSL_WANT_WRITE;

    if( mbedtls_mock_tcp_send_b( socket, buf, len ) != (int) len )
        return MBEDTLS_TEST_ERROR_SEND_FAILED;

    return mbedtls_test_message_queue_push_info( queue, len );
}

/*
 * Receive one message from a given message socket context and return message
 * length or an error.
 *
 * \retval  message length, if everything succeeds.
 * \retval  MBEDTLS_TEST_ERROR_CONTEXT_ERROR, if any of the needed context
 *          elements or the context itself is null.
 * \retval  MBEDTLS_TEST_ERROR_RECV_FAILED if mbedtls_mock_tcp_recv_b failed.
 *
 * This function will also return any error other than
 * MBEDTLS_TEST_ERROR_MESSAGE_TRUNCATED from mbedtls_test_message_queue_peek_info.
 */
int mbedtls_mock_tcp_recv_msg( void *ctx, unsigned char *buf, size_t buf_len )
{
    mbedtls_test_message_queue* queue;
    mbedtls_mock_socket* socket;
    mbedtls_test_message_socket_context *context = (mbedtls_test_message_socket_context*) ctx;
    size_t drop_len;
    size_t msg_len;
    int ret;

    if( context == NULL || context->socket == NULL
        || context->queue_input == NULL )
    {
        return MBEDTLS_TEST_ERROR_CONTEXT_ERROR;
    }

    queue = context->queue_input;
    socket = context->socket;

    /* Peek first, so that in case of a socket error the data remains in
     * the queue. */
    ret = mbedtls_test_message_queue_peek_info( queue, buf_len, &msg_len );
    if( ret == MBEDTLS_TEST_ERROR_MESSAGE_TRUNCATED )
    {
        /* Calculate how much to drop */
        drop_len = msg_len - buf_len;

        /* Set the requested message len to be buffer length */
        msg_len = buf_len;
    } else if( ret != 0 )
    {
        return ret;
    }

    if( mbedtls_mock_tcp_recv_b( socket, buf, msg_len ) != (int) msg_len )
        return MBEDTLS_TEST_ERROR_RECV_FAILED;

    if( ret == MBEDTLS_TEST_ERROR_MESSAGE_TRUNCATED )
    {
        /* Drop the remaining part of the message */
        if( mbedtls_mock_tcp_recv_b( socket, NULL, drop_len ) != (int) drop_len )
        {
          /* Inconsistent state - part of the message was read,
           * and a part couldn't. Not much we can do here, but it should not
           * happen in test environment, unless forced manually. */
        }
    }
    mbedtls_test_message_queue_pop_info( queue, buf_len );

    return msg_len;
}

#if defined(MBEDTLS_X509_CRT_PARSE_C)

/*
 * Structure with endpoint's certificates for SSL communication tests.
 */
typedef struct mbedtls_endpoint_certificate
{
    mbedtls_x509_crt ca_cert;
    mbedtls_x509_crt cert;
    mbedtls_pk_context pkey;
} mbedtls_endpoint_certificate;

/*
 * Endpoint structure for SSL communication tests.
 */
typedef struct mbedtls_endpoint
{
    const char *name;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_entropy_context entropy;
    mbedtls_mock_socket socket;
    mbedtls_endpoint_certificate cert;
} mbedtls_endpoint;

/*
 * Initializes \p ep_cert structure and assigns it to endpoint
 * represented by \p ep.
 *
 * \retval  0 on success, otherwise error code.
 */
int mbedtls_endpoint_certificate_init( mbedtls_endpoint *ep, int pk_alg )
{
    int i = 0;
    int ret = -1;
    mbedtls_endpoint_certificate *cert;

    if( ep == NULL )
    {
        return MBEDTLS_ERR_SSL_BAD_INPUT_DATA;
    }

    cert = &( ep->cert );
    mbedtls_x509_crt_init( &( cert->ca_cert ) );
    mbedtls_x509_crt_init( &( cert->cert ) );
    mbedtls_pk_init( &( cert->pkey ) );

    /* Load the trusted CA */

    for( i = 0; mbedtls_test_cas_der[i] != NULL; i++ )
    {
        ret = mbedtls_x509_crt_parse_der( &( cert->ca_cert ),
                        (const unsigned char *) mbedtls_test_cas_der[i],
                        mbedtls_test_cas_der_len[i] );
        TEST_ASSERT( ret == 0 );
    }

    /* Load own certificate and private key */

    if( ep->conf.endpoint == MBEDTLS_SSL_IS_SERVER )
    {
        if( pk_alg == MBEDTLS_PK_RSA )
        {
            ret = mbedtls_x509_crt_parse( &( cert->cert ),
                    (const unsigned char*) mbedtls_test_srv_crt_rsa_sha256_der,
                    mbedtls_test_srv_crt_rsa_sha256_der_len );
            TEST_ASSERT( ret == 0 );

            ret = mbedtls_pk_parse_key( &( cert->pkey ),
                            (const unsigned char*) mbedtls_test_srv_key_rsa_der,
                            mbedtls_test_srv_key_rsa_der_len, NULL, 0 );
            TEST_ASSERT( ret == 0 );
        }
        else
        {
            ret = mbedtls_x509_crt_parse( &( cert->cert ),
                            (const unsigned char*) mbedtls_test_srv_crt_ec_der,
                            mbedtls_test_srv_crt_ec_der_len );
            TEST_ASSERT( ret == 0 );

            ret = mbedtls_pk_parse_key( &( cert->pkey ),
                            (const unsigned char*) mbedtls_test_srv_key_ec_der,
                            mbedtls_test_srv_key_ec_der_len, NULL, 0 );
            TEST_ASSERT( ret == 0 );
        }
    }
    else
    {
        if( pk_alg == MBEDTLS_PK_RSA )
        {
            ret = mbedtls_x509_crt_parse( &( cert->cert ),
                          (const unsigned char *) mbedtls_test_cli_crt_rsa_der,
                          mbedtls_test_cli_crt_rsa_der_len );
            TEST_ASSERT( ret == 0 );

            ret = mbedtls_pk_parse_key( &( cert->pkey ),
                          (const unsigned char *) mbedtls_test_cli_key_rsa_der,
                          mbedtls_test_cli_key_rsa_der_len, NULL, 0 );
            TEST_ASSERT( ret == 0 );
        }
        else
        {
            ret = mbedtls_x509_crt_parse( &( cert->cert ),
                          (const unsigned char *) mbedtls_test_cli_crt_ec_der,
                          mbedtls_test_cli_crt_ec_len );
            TEST_ASSERT( ret == 0 );

            ret = mbedtls_pk_parse_key( &( cert->pkey ),
                          (const unsigned char *) mbedtls_test_cli_key_ec_der,
                          mbedtls_test_cli_key_ec_der_len, NULL, 0 );
            TEST_ASSERT( ret == 0 );
        }
    }

    mbedtls_ssl_conf_ca_chain( &( ep->conf ), &( cert->ca_cert ), NULL );

    ret = mbedtls_ssl_conf_own_cert( &( ep->conf ), &( cert->cert ),
                                     &( cert->pkey ) );
    TEST_ASSERT( ret == 0 );

exit:
    if( ret != 0 )
    {
        mbedtls_x509_crt_free( &( cert->ca_cert ) );
        mbedtls_x509_crt_free( &( cert->cert ) );
        mbedtls_pk_free( &( cert->pkey ) );
    }

    return ret;
}

/*
 * Initializes \p ep structure. It is important to call `mbedtls_endpoint_free()`
 * after calling this function even if it fails.
 *
 * \p endpoint_type must be set as MBEDTLS_SSL_IS_SERVER or
 * MBEDTLS_SSL_IS_CLIENT.
 * \p pk_alg the algorithm to use, currently only MBEDTLS_PK_RSA and
 * MBEDTLS_PK_ECDSA are supported.
 * \p dtls_context - in case of DTLS - this is the context handling metadata.
 * \p input_queue - used only in case of DTLS.
 * \p output_queue - used only in case of DTLS.
 *
 * \retval  0 on success, otherwise error code.
 */
int mbedtls_endpoint_init( mbedtls_endpoint *ep, int endpoint_type, int pk_alg,
                           mbedtls_test_message_socket_context *dtls_context,
                           mbedtls_test_message_queue *input_queue,
                           mbedtls_test_message_queue *output_queue )
{
    int ret = -1;

    if( dtls_context != NULL && ( input_queue == NULL || output_queue == NULL ) )
        return MBEDTLS_ERR_SSL_BAD_INPUT_DATA;

    if( ep == NULL )
        return MBEDTLS_ERR_SSL_BAD_INPUT_DATA;

    memset( ep, 0, sizeof( *ep ) );

    ep->name = ( endpoint_type == MBEDTLS_SSL_IS_SERVER ) ? "Server" : "Client";

    mbedtls_ssl_init( &( ep->ssl ) );
    mbedtls_ssl_config_init( &( ep->conf ) );
    mbedtls_ctr_drbg_init( &( ep->ctr_drbg ) );
    mbedtls_ssl_conf_rng( &( ep->conf ),
        mbedtls_ctr_drbg_random,
        &( ep->ctr_drbg ) );
    mbedtls_entropy_init( &( ep->entropy ) );
    if( dtls_context != NULL )
    {
        TEST_ASSERT( mbedtls_message_socket_setup( input_queue, output_queue,
                                                   100, &( ep->socket ),
                                                   dtls_context ) == 0 );
    }
    else
    {
        mbedtls_mock_socket_init( &( ep->socket ) );
    }

    ret = mbedtls_ctr_drbg_seed( &( ep->ctr_drbg ), mbedtls_entropy_func,
                    &( ep->entropy ), (const unsigned char *) ( ep->name ),
                    strlen( ep->name ) );
    TEST_ASSERT( ret == 0 );

    /* Non-blocking callbacks without timeout */
    if( dtls_context != NULL )
    {
        mbedtls_ssl_set_bio( &( ep->ssl ), dtls_context,
            mbedtls_mock_tcp_send_msg,
            mbedtls_mock_tcp_recv_msg,
            NULL );
    }
    else
    {
        mbedtls_ssl_set_bio( &( ep->ssl ), &( ep->socket ),
            mbedtls_mock_tcp_send_nb,
            mbedtls_mock_tcp_recv_nb,
            NULL );
    }

    ret = mbedtls_ssl_config_defaults( &( ep->conf ), endpoint_type,
                                       ( dtls_context != NULL ) ?
                                           MBEDTLS_SSL_TRANSPORT_DATAGRAM :
                                           MBEDTLS_SSL_TRANSPORT_STREAM,
                                       MBEDTLS_SSL_PRESET_DEFAULT );
    TEST_ASSERT( ret == 0 );

    ret = mbedtls_ssl_setup( &( ep->ssl ), &( ep->conf ) );
    TEST_ASSERT( ret == 0 );

#if defined(MBEDTLS_SSL_PROTO_DTLS) && defined(MBEDTLS_SSL_SRV_C)
    if( endpoint_type == MBEDTLS_SSL_IS_SERVER && dtls_context != NULL )
         mbedtls_ssl_conf_dtls_cookies( &( ep->conf ), NULL, NULL, NULL );
#endif

    ret = mbedtls_endpoint_certificate_init( ep, pk_alg );
    TEST_ASSERT( ret == 0 );

exit:
    return ret;
}

/*
 * Deinitializes certificates from endpoint represented by \p ep.
 */
void mbedtls_endpoint_certificate_free( mbedtls_endpoint *ep )
{
    mbedtls_endpoint_certificate *cert = &( ep->cert );
    mbedtls_x509_crt_free( &( cert->ca_cert ) );
    mbedtls_x509_crt_free( &( cert->cert ) );
    mbedtls_pk_free( &( cert->pkey ) );
}

/*
 * Deinitializes endpoint represented by \p ep.
 */
void mbedtls_endpoint_free( mbedtls_endpoint *ep,
                            mbedtls_test_message_socket_context *context )
{
    mbedtls_endpoint_certificate_free( ep );

    mbedtls_ssl_free( &( ep->ssl ) );
    mbedtls_ssl_config_free( &( ep->conf ) );
    mbedtls_ctr_drbg_free( &( ep->ctr_drbg ) );
    mbedtls_entropy_free( &( ep->entropy ) );

    if( context != NULL )
    {
        mbedtls_message_socket_close( context );
    }
    else
    {
        mbedtls_mock_socket_close( &( ep->socket ) );
    }
}

/*
 * This function moves ssl handshake from \p ssl to prescribed \p state.
 * /p second_ssl is used as second endpoint and their sockets have to be
 * connected before calling this function.
 *
 * \retval  0 on success, otherwise error code.
 */
int mbedtls_move_handshake_to_state( mbedtls_ssl_context *ssl,
                                     mbedtls_ssl_context *second_ssl,
                                     int state )
{
    enum { BUFFSIZE = 1024 };
    int max_steps = 1000;
    int ret = 0;

    if( ssl == NULL || second_ssl == NULL )
    {
        return MBEDTLS_ERR_SSL_BAD_INPUT_DATA;
    }

    /* Perform communication via connected sockets */
    while( ( ssl->state != state ) && ( --max_steps >= 0 ) )
    {
        /* If /p second_ssl ends the handshake procedure before /p ssl then
         * there is no need to call the next step */
        if( second_ssl->state != MBEDTLS_SSL_HANDSHAKE_OVER )
        {
            ret = mbedtls_ssl_handshake_step( second_ssl );
            if( ret != 0 && ret != MBEDTLS_ERR_SSL_WANT_READ &&
                            ret != MBEDTLS_ERR_SSL_WANT_WRITE )
            {
                return ret;
            }
        }

        /* We only care about the \p ssl state and returns, so we call it last,
         * to leave the iteration as soon as the state is as expected. */
        ret = mbedtls_ssl_handshake_step( ssl );
        if( ret != 0 && ret != MBEDTLS_ERR_SSL_WANT_READ &&
                        ret != MBEDTLS_ERR_SSL_WANT_WRITE )
        {
            return ret;
        }
    }

    return ( max_steps >= 0 ) ? ret : -1;
}

#endif /* MBEDTLS_X509_CRT_PARSE_C */

/*
 * Write application data. Increase write counter and fragments counter if
 * necessary.
 */
int mbedtls_ssl_write_fragment( mbedtls_ssl_context *ssl, unsigned char *buf,
                                int buf_len, int *written,
                                int *fragments, const int expected_fragments )
{
    int ret = mbedtls_ssl_write( ssl, buf + *written, buf_len - *written );
    if( ret > 0 )
    {
        (*fragments)++;
        *written += ret;
    }

    if( expected_fragments == 0 )
    {
        /* Used for DTLS and the message size larger than MFL. In that case
         * the message can not be fragmented and the library should return
         * MBEDTLS_ERR_SSL_BAD_INPUT_DATA error. This error must be returned
         * to prevent a dead loop inside mbedtls_exchange_data(). */
        return ret;
    }
    else if( expected_fragments == 1 )
    {
        /* Used for TLS/DTLS and the message size lower than MFL */
        TEST_ASSERT( ret == buf_len ||
                     ret == MBEDTLS_ERR_SSL_WANT_READ ||
                     ret == MBEDTLS_ERR_SSL_WANT_WRITE );
    }
    else
    {
        /* Used for TLS and the message size larger than MFL */
        TEST_ASSERT( expected_fragments > 1 );
        TEST_ASSERT( ( ret >= 0 && ret <= buf_len ) ||
                       ret == MBEDTLS_ERR_SSL_WANT_READ ||
                       ret == MBEDTLS_ERR_SSL_WANT_WRITE );
    }

    return 0;

exit:
    /* Some of the tests failed */
    return -1;
}

/*
 * Read application data and increase read counter if necessary.
 */
int mbedtls_ssl_read_fragment( mbedtls_ssl_context *ssl, unsigned char *buf,
                               int buf_len, int *read,
                               const int expected_fragments )
{
    int ret = mbedtls_ssl_read( ssl, buf + *read, buf_len - *read );
    if( ret > 0 )
    {
        *read += ret;
    }

    if( expected_fragments == 0 )
    {
        TEST_ASSERT( ret == 0 );
    }
    else if( expected_fragments == 1 )
    {
        TEST_ASSERT( ret == buf_len ||
                     ret == MBEDTLS_ERR_SSL_WANT_READ ||
                     ret == MBEDTLS_ERR_SSL_WANT_WRITE );
    }
    else
    {
        TEST_ASSERT( expected_fragments > 1 );
        TEST_ASSERT( ( ret >= 0 && ret <= buf_len ) ||
                       ret == MBEDTLS_ERR_SSL_WANT_READ ||
                       ret == MBEDTLS_ERR_SSL_WANT_WRITE );
    }

    return 0;

exit:
    /* Some of the tests failed */
    return -1;
}

/*
 * Helper function setting up inverse record transformations
 * using given cipher, hash, EtM mode, authentication tag length,
 * and version.
 */

#define CHK( x )                                \
    do                                          \
    {                                           \
        if( !( x ) )                            \
        {                                       \
            ret = -1;                           \
            goto cleanup;                       \
        }                                       \
    } while( 0 )

void set_ciphersuite( mbedtls_ssl_config *conf, const char *cipher,
                      int* forced_ciphersuite )
{
    const mbedtls_ssl_ciphersuite_t *ciphersuite_info;
    forced_ciphersuite[0] = mbedtls_ssl_get_ciphersuite_id( cipher );
    forced_ciphersuite[1] = 0;

    ciphersuite_info =
        mbedtls_ssl_ciphersuite_from_id( forced_ciphersuite[0] );

    TEST_ASSERT( ciphersuite_info != NULL );
    TEST_ASSERT( ciphersuite_info->min_minor_ver <= conf->max_minor_ver );
    TEST_ASSERT( ciphersuite_info->max_minor_ver >= conf->min_minor_ver );

    if( conf->max_minor_ver > ciphersuite_info->max_minor_ver )
    {
        conf->max_minor_ver = ciphersuite_info->max_minor_ver;
    }
    if( conf->min_minor_ver < ciphersuite_info->min_minor_ver )
    {
        conf->min_minor_ver = ciphersuite_info->min_minor_ver;
    }

    mbedtls_ssl_conf_ciphersuites( conf, forced_ciphersuite );

exit:
    return;
}

int psk_dummy_callback( void *p_info, mbedtls_ssl_context *ssl,
                  const unsigned char *name, size_t name_len )
{
    (void) p_info;
    (void) ssl;
    (void) name;
    (void) name_len;

    return ( 0 );
}

#if MBEDTLS_SSL_CID_OUT_LEN_MAX > MBEDTLS_SSL_CID_IN_LEN_MAX
#define SSL_CID_LEN_MIN MBEDTLS_SSL_CID_IN_LEN_MAX
#else
#define SSL_CID_LEN_MIN MBEDTLS_SSL_CID_OUT_LEN_MAX
#endif

static int build_transforms( mbedtls_ssl_transform *t_in,
                             mbedtls_ssl_transform *t_out,
                             int cipher_type, int hash_id,
                             int etm, int tag_mode, int ver,
                             size_t cid0_len,
                             size_t cid1_len )
{
    mbedtls_cipher_info_t const *cipher_info;
    int ret = 0;

    size_t keylen, maclen, ivlen;
    unsigned char *key0 = NULL, *key1 = NULL;
    unsigned char iv_enc[16], iv_dec[16];

#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
    unsigned char cid0[ SSL_CID_LEN_MIN ];
    unsigned char cid1[ SSL_CID_LEN_MIN ];

    rnd_std_rand( NULL, cid0, sizeof( cid0 ) );
    rnd_std_rand( NULL, cid1, sizeof( cid1 ) );
#else
    ((void) cid0_len);
    ((void) cid1_len);
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

    maclen = 0;

    /* Pick cipher */
    cipher_info = mbedtls_cipher_info_from_type( cipher_type );
    CHK( cipher_info != NULL );
    CHK( cipher_info->iv_size <= 16 );
    CHK( cipher_info->key_bitlen % 8 == 0 );

    /* Pick keys */
    keylen = cipher_info->key_bitlen / 8;
    /* Allocate `keylen + 1` bytes to ensure that we get
     * a non-NULL pointers from `mbedtls_calloc` even if
     * `keylen == 0` in the case of the NULL cipher. */
    CHK( ( key0 = mbedtls_calloc( 1, keylen + 1 ) ) != NULL );
    CHK( ( key1 = mbedtls_calloc( 1, keylen + 1 ) ) != NULL );
    memset( key0, 0x1, keylen );
    memset( key1, 0x2, keylen );

    /* Setup cipher contexts */
    CHK( mbedtls_cipher_setup( &t_in->cipher_ctx_enc,  cipher_info ) == 0 );
    CHK( mbedtls_cipher_setup( &t_in->cipher_ctx_dec,  cipher_info ) == 0 );
    CHK( mbedtls_cipher_setup( &t_out->cipher_ctx_enc, cipher_info ) == 0 );
    CHK( mbedtls_cipher_setup( &t_out->cipher_ctx_dec, cipher_info ) == 0 );

#if defined(MBEDTLS_CIPHER_MODE_CBC)
    if( cipher_info->mode == MBEDTLS_MODE_CBC )
    {
        CHK( mbedtls_cipher_set_padding_mode( &t_in->cipher_ctx_enc,
                                              MBEDTLS_PADDING_NONE ) == 0 );
        CHK( mbedtls_cipher_set_padding_mode( &t_in->cipher_ctx_dec,
                                              MBEDTLS_PADDING_NONE ) == 0 );
        CHK( mbedtls_cipher_set_padding_mode( &t_out->cipher_ctx_enc,
                                              MBEDTLS_PADDING_NONE ) == 0 );
        CHK( mbedtls_cipher_set_padding_mode( &t_out->cipher_ctx_dec,
                                              MBEDTLS_PADDING_NONE ) == 0 );
    }
#endif /* MBEDTLS_CIPHER_MODE_CBC */

    CHK( mbedtls_cipher_setkey( &t_in->cipher_ctx_enc, key0,
                                keylen << 3, MBEDTLS_ENCRYPT ) == 0 );
    CHK( mbedtls_cipher_setkey( &t_in->cipher_ctx_dec, key1,
                                keylen << 3, MBEDTLS_DECRYPT ) == 0 );
    CHK( mbedtls_cipher_setkey( &t_out->cipher_ctx_enc, key1,
                                keylen << 3, MBEDTLS_ENCRYPT ) == 0 );
    CHK( mbedtls_cipher_setkey( &t_out->cipher_ctx_dec, key0,
                                keylen << 3, MBEDTLS_DECRYPT ) == 0 );

    /* Setup MAC contexts */
#if defined(MBEDTLS_SSL_SOME_MODES_USE_MAC)
    if( cipher_info->mode == MBEDTLS_MODE_CBC ||
        cipher_info->mode == MBEDTLS_MODE_STREAM )
    {
        mbedtls_md_info_t const *md_info;
        unsigned char *md0, *md1;

        /* Pick hash */
        md_info = mbedtls_md_info_from_type( hash_id );
        CHK( md_info != NULL );

        /* Pick hash keys */
        maclen = mbedtls_md_get_size( md_info );
        CHK( ( md0 = mbedtls_calloc( 1, maclen ) ) != NULL );
        CHK( ( md1 = mbedtls_calloc( 1, maclen ) ) != NULL );
        memset( md0, 0x5, maclen );
        memset( md1, 0x6, maclen );

        CHK( mbedtls_md_setup( &t_out->md_ctx_enc, md_info, 1 ) == 0 );
        CHK( mbedtls_md_setup( &t_out->md_ctx_dec, md_info, 1 ) == 0 );
        CHK( mbedtls_md_setup( &t_in->md_ctx_enc,  md_info, 1 ) == 0 );
        CHK( mbedtls_md_setup( &t_in->md_ctx_dec,  md_info, 1 ) == 0 );

        if( ver > MBEDTLS_SSL_MINOR_VERSION_0 )
        {
            CHK( mbedtls_md_hmac_starts( &t_in->md_ctx_enc,
                                         md0, maclen ) == 0 );
            CHK( mbedtls_md_hmac_starts( &t_in->md_ctx_dec,
                                         md1, maclen ) == 0 );
            CHK( mbedtls_md_hmac_starts( &t_out->md_ctx_enc,
                                         md1, maclen ) == 0 );
            CHK( mbedtls_md_hmac_starts( &t_out->md_ctx_dec,
                                         md0, maclen ) == 0 );
        }
#if defined(MBEDTLS_SSL_PROTO_SSL3)
        else
        {
            memcpy( &t_in->mac_enc, md0, maclen );
            memcpy( &t_in->mac_dec, md1, maclen );
            memcpy( &t_out->mac_enc, md1, maclen );
            memcpy( &t_out->mac_dec, md0, maclen );
        }
#endif

        mbedtls_free( md0 );
        mbedtls_free( md1 );
    }
#else
    ((void) hash_id);
#endif /* MBEDTLS_SSL_SOME_MODES_USE_MAC */


    /* Pick IV's (regardless of whether they
     * are being used by the transform). */
    ivlen = cipher_info->iv_size;
    memset( iv_enc, 0x3, sizeof( iv_enc ) );
    memset( iv_dec, 0x4, sizeof( iv_dec ) );

    /*
     * Setup transforms
     */

#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC) && \
    defined(MBEDTLS_SSL_SOME_MODES_USE_MAC)
    t_out->encrypt_then_mac = etm;
    t_in->encrypt_then_mac = etm;
#else
    ((void) etm);
#endif

    t_out->minor_ver = ver;
    t_in->minor_ver = ver;
    t_out->ivlen = ivlen;
    t_in->ivlen = ivlen;

    switch( cipher_info->mode )
    {
        case MBEDTLS_MODE_GCM:
        case MBEDTLS_MODE_CCM:
            t_out->fixed_ivlen = 4;
            t_in->fixed_ivlen = 4;
            t_out->maclen = 0;
            t_in->maclen = 0;
            switch( tag_mode )
            {
                case 0: /* Full tag */
                    t_out->taglen = 16;
                    t_in->taglen = 16;
                    break;
                case 1: /* Partial tag */
                    t_out->taglen = 8;
                    t_in->taglen = 8;
                    break;
                default:
                    return( 1 );
            }
            break;

        case MBEDTLS_MODE_CHACHAPOLY:
            t_out->fixed_ivlen = 12;
            t_in->fixed_ivlen = 12;
            t_out->maclen = 0;
            t_in->maclen = 0;
            switch( tag_mode )
            {
                case 0: /* Full tag */
                    t_out->taglen = 16;
                    t_in->taglen = 16;
                    break;
                case 1: /* Partial tag */
                    t_out->taglen = 8;
                    t_in->taglen = 8;
                    break;
                default:
                    return( 1 );
            }
            break;

        case MBEDTLS_MODE_STREAM:
        case MBEDTLS_MODE_CBC:
            t_out->fixed_ivlen = 0; /* redundant, must be 0 */
            t_in->fixed_ivlen = 0;  /* redundant, must be 0 */
            t_out->taglen = 0;
            t_in->taglen = 0;
            switch( tag_mode )
            {
                case 0: /* Full tag */
                    t_out->maclen = maclen;
                    t_in->maclen = maclen;
                    break;
                case 1: /* Partial tag */
                    t_out->maclen = 10;
                    t_in->maclen = 10;
                    break;
                default:
                    return( 1 );
            }
            break;
        default:
            return( 1 );
            break;
    }

    /* Setup IV's */

    memcpy( &t_in->iv_dec, iv_dec, sizeof( iv_dec ) );
    memcpy( &t_in->iv_enc, iv_enc, sizeof( iv_enc ) );
    memcpy( &t_out->iv_dec, iv_enc, sizeof( iv_enc ) );
    memcpy( &t_out->iv_enc, iv_dec, sizeof( iv_dec ) );

#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
    /* Add CID */
    memcpy( &t_in->in_cid,  cid0, cid0_len );
    memcpy( &t_in->out_cid, cid1, cid1_len );
    t_in->in_cid_len = cid0_len;
    t_in->out_cid_len = cid1_len;
    memcpy( &t_out->in_cid,  cid1, cid1_len );
    memcpy( &t_out->out_cid, cid0, cid0_len );
    t_out->in_cid_len = cid1_len;
    t_out->out_cid_len = cid0_len;
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

cleanup:

    mbedtls_free( key0 );
    mbedtls_free( key1 );

    return( ret );
}

/*
 * Populate a session structure for serialization tests.
 * Choose dummy values, mostly non-0 to distinguish from the init default.
 */
static int ssl_populate_session( mbedtls_ssl_session *session,
                                 int ticket_len,
                                 const char *crt_file )
{
#if defined(MBEDTLS_HAVE_TIME)
    session->start = mbedtls_time( NULL ) - 42;
#endif
    session->ciphersuite = 0xabcd;
    session->compression = 1;
    session->id_len = sizeof( session->id );
    memset( session->id, 66, session->id_len );
    memset( session->master, 17, sizeof( session->master ) );

#if defined(MBEDTLS_X509_CRT_PARSE_C) && defined(MBEDTLS_FS_IO)
    if( strlen( crt_file ) != 0 )
    {
        mbedtls_x509_crt tmp_crt;
        int ret;

        mbedtls_x509_crt_init( &tmp_crt );
        ret = mbedtls_x509_crt_parse_file( &tmp_crt, crt_file );
        if( ret != 0 )
            return( ret );

#if defined(MBEDTLS_SSL_KEEP_PEER_CERTIFICATE)
        /* Move temporary CRT. */
        session->peer_cert = mbedtls_calloc( 1, sizeof( *session->peer_cert ) );
        if( session->peer_cert == NULL )
            return( -1 );
        *session->peer_cert = tmp_crt;
        memset( &tmp_crt, 0, sizeof( tmp_crt ) );
#else /* MBEDTLS_SSL_KEEP_PEER_CERTIFICATE */
        /* Calculate digest of temporary CRT. */
        session->peer_cert_digest =
            mbedtls_calloc( 1, MBEDTLS_SSL_PEER_CERT_DIGEST_DFL_LEN );
        if( session->peer_cert_digest == NULL )
            return( -1 );
        ret = mbedtls_md( mbedtls_md_info_from_type(
                              MBEDTLS_SSL_PEER_CERT_DIGEST_DFL_TYPE ),
                          tmp_crt.raw.p, tmp_crt.raw.len,
                          session->peer_cert_digest );
        if( ret != 0 )
            return( ret );
        session->peer_cert_digest_type =
            MBEDTLS_SSL_PEER_CERT_DIGEST_DFL_TYPE;
        session->peer_cert_digest_len =
            MBEDTLS_SSL_PEER_CERT_DIGEST_DFL_LEN;
#endif /* MBEDTLS_SSL_KEEP_PEER_CERTIFICATE */

        mbedtls_x509_crt_free( &tmp_crt );
    }
#else /* MBEDTLS_X509_CRT_PARSE_C && MBEDTLS_FS_IO */
    (void) crt_file;
#endif /* MBEDTLS_X509_CRT_PARSE_C && MBEDTLS_FS_IO */
    session->verify_result = 0xdeadbeef;

#if defined(MBEDTLS_SSL_SESSION_TICKETS) && defined(MBEDTLS_SSL_CLI_C)
    if( ticket_len != 0 )
    {
        session->ticket = mbedtls_calloc( 1, ticket_len );
        if( session->ticket == NULL )
            return( -1 );
        memset( session->ticket, 33, ticket_len );
    }
    session->ticket_len = ticket_len;
    session->ticket_lifetime = 86401;
#else
    (void) ticket_len;
#endif

#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
    session->mfl_code = 1;
#endif
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
    session->trunc_hmac = 1;
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
    session->encrypt_then_mac = 1;
#endif

    return( 0 );
}

/*
 * Perform data exchanging between \p ssl_1 and \p ssl_2 and check if the
 * message was sent in the correct number of fragments.
 *
 * /p ssl_1 and /p ssl_2    Endpoints represented by mbedtls_ssl_context. Both
 *                          of them must be initialized and connected beforehand.
 * /p msg_len_1 and /p msg_len_2 specify the size of the message to send.
 * /p expected_fragments_1 and /p expected_fragments_2 determine in how many
 *                          fragments the message should be sent.
 *      expected_fragments is 0: can be used for DTLS testing while the message
 *                          size is larger than MFL. In that case the message
 *                          cannot be fragmented and sent to the second endpoint.
 *                          This value can be used for negative tests.
 *      expected_fragments is 1: can be used for TLS/DTLS testing while the
 *                          message size is below MFL
 *      expected_fragments > 1: can be used for TLS testing while the message
 *                          size is larger than MFL
 *
 * \retval  0 on success, otherwise error code.
 */
int mbedtls_exchange_data( mbedtls_ssl_context *ssl_1,
                           int msg_len_1, const int expected_fragments_1,
                           mbedtls_ssl_context *ssl_2,
                           int msg_len_2, const int expected_fragments_2 )
{
    unsigned char *msg_buf_1 = malloc( msg_len_1 );
    unsigned char *msg_buf_2 = malloc( msg_len_2 );
    unsigned char *in_buf_1  = malloc( msg_len_2 );
    unsigned char *in_buf_2  = malloc( msg_len_1 );
    int msg_type, ret = -1;

    /* Perform this test with two message types. At first use a message
     * consisting of only 0x00 for the client and only 0xFF for the server.
     * At the second time use message with generated data */
    for( msg_type = 0; msg_type < 2; msg_type++ )
    {
        int written_1 = 0;
        int written_2 = 0;
        int read_1 = 0;
        int read_2 = 0;
        int fragments_1 = 0;
        int fragments_2 = 0;

        if( msg_type == 0 )
        {
            memset( msg_buf_1, 0x00, msg_len_1 );
            memset( msg_buf_2, 0xff, msg_len_2 );
        }
        else
        {
            int i, j = 0;
            for( i = 0; i < msg_len_1; i++ )
            {
                msg_buf_1[i] = j++ & 0xFF;
            }
            for( i = 0; i < msg_len_2; i++ )
            {
                msg_buf_2[i] = ( j -= 5 ) & 0xFF;
            }
        }

        while( read_1 < msg_len_2 || read_2 < msg_len_1 )
        {
            /* ssl_1 sending */
            if( msg_len_1 > written_1 )
            {
                ret = mbedtls_ssl_write_fragment( ssl_1, msg_buf_1,
                                                  msg_len_1, &written_1,
                                                  &fragments_1,
                                                  expected_fragments_1 );
                if( expected_fragments_1 == 0 )
                {
                    /* This error is expected when the message is too large and
                     * cannot be fragmented */
                    TEST_ASSERT( ret == MBEDTLS_ERR_SSL_BAD_INPUT_DATA );
                    msg_len_1 = 0;
                }
                else
                {
                    TEST_ASSERT( ret == 0 );
                }
            }

            /* ssl_2 sending */
            if( msg_len_2 > written_2 )
            {
                ret = mbedtls_ssl_write_fragment( ssl_2, msg_buf_2,
                                                  msg_len_2, &written_2,
                                                  &fragments_2,
                                                  expected_fragments_2 );
                if( expected_fragments_2 == 0 )
                {
                    /* This error is expected when the message is too large and
                     * cannot be fragmented */
                    TEST_ASSERT( ret == MBEDTLS_ERR_SSL_BAD_INPUT_DATA );
                    msg_len_2 = 0;
                }
                else
                {
                    TEST_ASSERT( ret == 0 );
                }
            }

            /* ssl_1 reading */
            if( read_1 < msg_len_2 )
            {
                ret = mbedtls_ssl_read_fragment( ssl_1, in_buf_1,
                                                 msg_len_2, &read_1,
                                                 expected_fragments_1 );
                TEST_ASSERT( ret == 0 );
            }

            /* ssl_2 reading */
            if( read_2 < msg_len_1 )
            {
                ret = mbedtls_ssl_read_fragment( ssl_2, in_buf_2,
                                                 msg_len_1, &read_2,
                                                 expected_fragments_2 );
                TEST_ASSERT( ret == 0 );
            }
        }

        ret = -1;
        TEST_ASSERT( 0 == memcmp( msg_buf_1, in_buf_2, msg_len_1 ) );
        TEST_ASSERT( 0 == memcmp( msg_buf_2, in_buf_1, msg_len_2 ) );
        TEST_ASSERT( fragments_1 == expected_fragments_1 );
        TEST_ASSERT( fragments_2 == expected_fragments_2 );
    }

    ret = 0;

exit:
    free( msg_buf_1 );
    free( in_buf_1 );
    free( msg_buf_2 );
    free( in_buf_2 );

    return ret;
}

/*
 * Perform data exchanging between \p ssl_1 and \p ssl_2. Both of endpoints
 * must be initialized and connected beforehand.
 *
 * \retval  0 on success, otherwise error code.
 */
int exchange_data( mbedtls_ssl_context *ssl_1,
                   mbedtls_ssl_context *ssl_2 )
{
    return mbedtls_exchange_data( ssl_1, 256, 1,
                                  ssl_2, 256, 1 );
}

#if defined(MBEDTLS_X509_CRT_PARSE_C)
void perform_handshake( handshake_test_options* options )
{
    /* forced_ciphersuite needs to last until the end of the handshake */
    int forced_ciphersuite[2];
    enum { BUFFSIZE = 17000 };
    mbedtls_endpoint client, server;
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
    const char *psk_identity = "foo";
#endif
#if defined(MBEDTLS_TIMING_C)
    mbedtls_timing_delay_context timer_client, timer_server;
#endif
#if defined(MBEDTLS_SSL_CONTEXT_SERIALIZATION)
    unsigned char *context_buf = NULL;
    size_t context_buf_len;
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
    int ret = -1;
#endif


    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    /* Client side */
    if( options->dtls != 0 )
    {
        TEST_ASSERT( mbedtls_endpoint_init( &client, MBEDTLS_SSL_IS_CLIENT,
                                            options->pk_alg, &client_context,
                                            &client_queue,
                                            &server_queue ) == 0 );
#if defined(MBEDTLS_TIMING_C)
        mbedtls_ssl_set_timer_cb( &client.ssl, &timer_client,
                                  mbedtls_timing_set_delay,
                                  mbedtls_timing_get_delay );
#endif
    }
    else
    {
        TEST_ASSERT( mbedtls_endpoint_init( &client, MBEDTLS_SSL_IS_CLIENT,
                                            options->pk_alg, NULL, NULL,
                                            NULL ) == 0 );
    }
    mbedtls_ssl_conf_min_version( &client.conf, MBEDTLS_SSL_MAJOR_VERSION_3,
                                      options->version );
    mbedtls_ssl_conf_max_version( &client.conf, MBEDTLS_SSL_MAJOR_VERSION_3,
                                      options->version );

    if( strlen( options->cipher ) > 0 )
    {
        set_ciphersuite( &client.conf, options->cipher, forced_ciphersuite );
    }

#if defined (MBEDTLS_DEBUG_C)
    if( options->cli_log_fun )
    {
        mbedtls_debug_set_threshold( 4 );
        mbedtls_ssl_conf_dbg( &client.conf, options->cli_log_fun,
                                            options->cli_log_obj );
    }
#endif

    /* Server side */
    if( options->dtls != 0 )
    {
        TEST_ASSERT( mbedtls_endpoint_init( &server, MBEDTLS_SSL_IS_SERVER,
                                            options->pk_alg, &server_context,
                                            &server_queue,
                                            &client_queue) == 0 );
#if defined(MBEDTLS_TIMING_C)
        mbedtls_ssl_set_timer_cb( &server.ssl, &timer_server,
                                  mbedtls_timing_set_delay,
                                  mbedtls_timing_get_delay );
#endif
    }
    else
    {
        TEST_ASSERT( mbedtls_endpoint_init( &server, MBEDTLS_SSL_IS_SERVER,
                                            options->pk_alg, NULL, NULL, NULL ) == 0 );
    }

    mbedtls_ssl_conf_authmode( &server.conf, options->srv_auth_mode );

    mbedtls_ssl_conf_min_version( &server.conf, MBEDTLS_SSL_MAJOR_VERSION_3,
                                      options->version );
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
    TEST_ASSERT( mbedtls_ssl_conf_max_frag_len( &(server.conf),
                                         (unsigned char) options->mfl ) == 0 );
    TEST_ASSERT( mbedtls_ssl_conf_max_frag_len( &(client.conf),
                                         (unsigned char) options->mfl ) == 0 );
#else
    TEST_ASSERT( MBEDTLS_SSL_MAX_FRAG_LEN_NONE == options->mfl );
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */

#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
    if( options->psk_str != NULL && options->psk_str->len > 0 )
    {
        TEST_ASSERT( mbedtls_ssl_conf_psk( &client.conf, options->psk_str->x,
                             options->psk_str->len,
                             (const unsigned char *) psk_identity,
                             strlen( psk_identity ) ) == 0 );

        TEST_ASSERT( mbedtls_ssl_conf_psk( &server.conf, options->psk_str->x,
                             options->psk_str->len,
                             (const unsigned char *) psk_identity,
                             strlen( psk_identity ) ) == 0 );

        mbedtls_ssl_conf_psk_cb( &server.conf, psk_dummy_callback, NULL );
    }
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
    if( options->renegotiate )
    {
        mbedtls_ssl_conf_renegotiation( &(server.conf),
                                        MBEDTLS_SSL_RENEGOTIATION_ENABLED );
        mbedtls_ssl_conf_renegotiation( &(client.conf),
                                        MBEDTLS_SSL_RENEGOTIATION_ENABLED );

        mbedtls_ssl_conf_legacy_renegotiation( &(server.conf),
                                               options->legacy_renegotiation );
        mbedtls_ssl_conf_legacy_renegotiation( &(client.conf),
                                               options->legacy_renegotiation );
    }
#endif /* MBEDTLS_SSL_RENEGOTIATION */

#if defined (MBEDTLS_DEBUG_C)
    if( options->srv_log_fun )
    {
        mbedtls_debug_set_threshold( 4 );
        mbedtls_ssl_conf_dbg( &server.conf, options->srv_log_fun,
                                            options->srv_log_obj );
    }
#endif

    TEST_ASSERT( mbedtls_mock_socket_connect( &(client.socket),
                                              &(server.socket),
                                              BUFFSIZE ) == 0 );

    TEST_ASSERT( mbedtls_move_handshake_to_state( &(client.ssl),
                                                  &(server.ssl),
                                                  MBEDTLS_SSL_HANDSHAKE_OVER )
                 == 0 );
    TEST_ASSERT( client.ssl.state == MBEDTLS_SSL_HANDSHAKE_OVER );
    TEST_ASSERT( server.ssl.state == MBEDTLS_SSL_HANDSHAKE_OVER );

    if( options->cli_msg_len != 0 || options->srv_msg_len != 0 )
    {
        /* Start data exchanging test */
        TEST_ASSERT( mbedtls_exchange_data( &(client.ssl), options->cli_msg_len,
                                            options->expected_cli_fragments,
                                            &(server.ssl), options->srv_msg_len,
                                            options->expected_srv_fragments )
                     == 0 );
    }
#if defined(MBEDTLS_SSL_CONTEXT_SERIALIZATION)
    if( options->serialize == 1 )
    {
        TEST_ASSERT( options->dtls == 1 );

        TEST_ASSERT( mbedtls_ssl_context_save( &(server.ssl), NULL,
                                               0, &context_buf_len )
                                             == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );

        context_buf = mbedtls_calloc( 1, context_buf_len );
        TEST_ASSERT( context_buf != NULL );

        TEST_ASSERT( mbedtls_ssl_context_save( &(server.ssl), context_buf,
                                               context_buf_len,
                                               &context_buf_len ) == 0 );

        mbedtls_ssl_free( &(server.ssl) );
        mbedtls_ssl_init( &(server.ssl) );

        TEST_ASSERT( mbedtls_ssl_setup( &(server.ssl), &(server.conf) ) == 0 );

        mbedtls_ssl_set_bio( &( server.ssl ), &server_context,
                             mbedtls_mock_tcp_send_msg,
                             mbedtls_mock_tcp_recv_msg,
                             NULL );

#if defined(MBEDTLS_TIMING_C)
        mbedtls_ssl_set_timer_cb( &server.ssl, &timer_server,
                                  mbedtls_timing_set_delay,
                                  mbedtls_timing_get_delay );
#endif
        TEST_ASSERT( mbedtls_ssl_context_load( &( server.ssl ), context_buf,
                                               context_buf_len ) == 0 );

        /* Retest writing/reading */
        if( options->cli_msg_len != 0 || options->srv_msg_len != 0 )
        {
            TEST_ASSERT( mbedtls_exchange_data( &(client.ssl),
                                                options->cli_msg_len,
                                                options->expected_cli_fragments,
                                                &(server.ssl),
                                                options->srv_msg_len,
                                                options->expected_srv_fragments )
                                                == 0 );
        }
    }
#endif /* MBEDTLS_SSL_CONTEXT_SERIALIZATION */
#if defined(MBEDTLS_SSL_RENEGOTIATION)
    if( options->renegotiate )
    {
        /* Start test with renegotiation */
        TEST_ASSERT( server.ssl.renego_status ==
                     MBEDTLS_SSL_INITIAL_HANDSHAKE );
        TEST_ASSERT( client.ssl.renego_status ==
                     MBEDTLS_SSL_INITIAL_HANDSHAKE );

        /* After calling this function for the server, it only sends a handshake
         * request. All renegotiation should happen during data exchanging */
        TEST_ASSERT( mbedtls_ssl_renegotiate( &(server.ssl) ) == 0 );
        TEST_ASSERT( server.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_PENDING );
        TEST_ASSERT( client.ssl.renego_status ==
                     MBEDTLS_SSL_INITIAL_HANDSHAKE );

        TEST_ASSERT( exchange_data( &(client.ssl), &(server.ssl) ) == 0 );
        TEST_ASSERT( server.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_DONE );
        TEST_ASSERT( client.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_DONE );

        /* After calling mbedtls_ssl_renegotiate for the client all renegotiation
         * should happen inside this function. However in this test, we cannot
         * perform simultaneous communication betwen client and server so this
         * function will return waiting error on the socket. All rest of
         * renegotiation should happen during data exchanging */
        ret = mbedtls_ssl_renegotiate( &(client.ssl) );
        TEST_ASSERT( ret == 0 ||
                     ret == MBEDTLS_ERR_SSL_WANT_READ ||
                     ret == MBEDTLS_ERR_SSL_WANT_WRITE );
        TEST_ASSERT( server.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_DONE );
        TEST_ASSERT( client.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_IN_PROGRESS );

        TEST_ASSERT( exchange_data( &(client.ssl), &(server.ssl) ) == 0 );
        TEST_ASSERT( server.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_DONE );
        TEST_ASSERT( client.ssl.renego_status ==
                     MBEDTLS_SSL_RENEGOTIATION_DONE );
    }
#endif /* MBEDTLS_SSL_RENEGOTIATION */

exit:
    mbedtls_endpoint_free( &client, options->dtls != 0 ? &client_context : NULL );
    mbedtls_endpoint_free( &server, options->dtls != 0 ? &server_context : NULL );
#if defined (MBEDTLS_DEBUG_C)
    if( options->cli_log_fun || options->srv_log_fun )
    {
        mbedtls_debug_set_threshold( 0 );
    }
#endif
#if defined(MBEDTLS_SSL_CONTEXT_SERIALIZATION)
    if( context_buf != NULL )
        mbedtls_free( context_buf );
#endif
}
#endif /* MBEDTLS_X509_CRT_PARSE_C */

#line 1902 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_test_callback_buffer_sanity()
{
    enum { MSGLEN = 10 };
    mbedtls_test_buffer buf;
    unsigned char input[MSGLEN];
    unsigned char output[MSGLEN];

    memset( input, 0, sizeof(input) );

    /* Make sure calling put and get on NULL buffer results in error. */
    TEST_ASSERT( mbedtls_test_buffer_put( NULL, input, sizeof( input ) )
                    == -1 );
    TEST_ASSERT( mbedtls_test_buffer_get( NULL, output, sizeof( output ) )
                    == -1 );
    TEST_ASSERT( mbedtls_test_buffer_put( NULL, NULL, sizeof( input ) ) == -1 );

    TEST_ASSERT( mbedtls_test_buffer_put( NULL, NULL, 0 ) == -1 );
    TEST_ASSERT( mbedtls_test_buffer_get( NULL, NULL, 0 ) == -1 );

    /* Make sure calling put and get on a buffer that hasn't been set up results
     * in eror. */
    mbedtls_test_buffer_init( &buf );

    TEST_ASSERT( mbedtls_test_buffer_put( &buf, input, sizeof( input ) ) == -1 );
    TEST_ASSERT( mbedtls_test_buffer_get( &buf, output, sizeof( output ) )
                    == -1 );
    TEST_ASSERT( mbedtls_test_buffer_put( &buf, NULL, sizeof( input ) ) == -1 );

    TEST_ASSERT( mbedtls_test_buffer_put( &buf, NULL, 0 ) == -1 );
    TEST_ASSERT( mbedtls_test_buffer_get( &buf, NULL, 0 ) == -1 );

    /* Make sure calling put and get on NULL input only results in
     * error if the length is not zero, and that a NULL output is valid for data
     * dropping.
     */

    TEST_ASSERT( mbedtls_test_buffer_setup( &buf, sizeof( input ) ) == 0 );

    TEST_ASSERT( mbedtls_test_buffer_put( &buf, NULL, sizeof( input ) ) == -1 );
    TEST_ASSERT( mbedtls_test_buffer_get( &buf, NULL, sizeof( output ) )
                    == 0 );
    TEST_ASSERT( mbedtls_test_buffer_put( &buf, NULL, 0 ) == 0 );
    TEST_ASSERT( mbedtls_test_buffer_get( &buf, NULL, 0 ) == 0 );

    /* Make sure calling put several times in the row is safe */

    TEST_ASSERT( mbedtls_test_buffer_put( &buf, input, sizeof( input ) )
                                          == sizeof( input ) );
    TEST_ASSERT( mbedtls_test_buffer_get( &buf, output, 2 ) == 2 );
    TEST_ASSERT( mbedtls_test_buffer_put( &buf, input, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_buffer_put( &buf, input, 2 ) == 1 );
    TEST_ASSERT( mbedtls_test_buffer_put( &buf, input, 2 ) == 0 );


exit:

    mbedtls_test_buffer_free( &buf );
}

void test_test_callback_buffer_sanity_wrapper( void ** params )
{
    (void)params;

    test_test_callback_buffer_sanity(  );
}
#line 1976 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_test_callback_buffer( int size, int put1, int put1_ret,
                           int get1, int get1_ret, int put2, int put2_ret,
                           int get2, int get2_ret )
{
    enum { ROUNDS = 2 };
    size_t put[ROUNDS];
    int put_ret[ROUNDS];
    size_t get[ROUNDS];
    int get_ret[ROUNDS];
    mbedtls_test_buffer buf;
    unsigned char* input = NULL;
    size_t input_len;
    unsigned char* output = NULL;
    size_t output_len;
    size_t i, j, written, read;

    mbedtls_test_buffer_init( &buf );
    TEST_ASSERT( mbedtls_test_buffer_setup( &buf, size ) == 0 );

    /* Check the sanity of input parameters and initialise local variables. That
     * is, ensure that the amount of data is not negative and that we are not
     * expecting more to put or get than we actually asked for. */
    TEST_ASSERT( put1 >= 0 );
    put[0] = put1;
    put_ret[0] = put1_ret;
    TEST_ASSERT( put1_ret <= put1 );
    TEST_ASSERT( put2 >= 0 );
    put[1] = put2;
    put_ret[1] = put2_ret;
    TEST_ASSERT( put2_ret <= put2 );

    TEST_ASSERT( get1 >= 0 );
    get[0] = get1;
    get_ret[0] = get1_ret;
    TEST_ASSERT( get1_ret <= get1 );
    TEST_ASSERT( get2 >= 0 );
    get[1] = get2;
    get_ret[1] = get2_ret;
    TEST_ASSERT( get2_ret <= get2 );

    input_len = 0;
    /* Calculate actual input and output lengths */
    for( j = 0; j < ROUNDS; j++ )
    {
        if( put_ret[j] > 0 )
        {
            input_len += put_ret[j];
        }
    }
    /* In order to always have a valid pointer we always allocate at least 1
     * byte. */
    if( input_len == 0 )
        input_len = 1;
    ASSERT_ALLOC( input, input_len );

    output_len = 0;
    for( j = 0; j < ROUNDS; j++ )
    {
        if( get_ret[j] > 0 )
        {
            output_len += get_ret[j];
        }
    }
    TEST_ASSERT( output_len <= input_len );
    /* In order to always have a valid pointer we always allocate at least 1
     * byte. */
    if( output_len == 0 )
        output_len = 1;
    ASSERT_ALLOC( output, output_len );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < input_len; i++ )
    {
        input[i] = i & 0xFF;
    }

    written = read = 0;
    for( j = 0; j < ROUNDS; j++ )
    {
        TEST_ASSERT( put_ret[j] == mbedtls_test_buffer_put( &buf,
                                        input + written, put[j] ) );
        written += put_ret[j];
        TEST_ASSERT( get_ret[j] == mbedtls_test_buffer_get( &buf,
                                        output + read, get[j] ) );
        read += get_ret[j];
        TEST_ASSERT( read <= written );
        if( get_ret[j] > 0 )
        {
            TEST_ASSERT( memcmp( output + read - get_ret[j],
                                 input + read - get_ret[j], get_ret[j] )
                         == 0 );
        }
    }

exit:

    mbedtls_free( input );
    mbedtls_free( output );
    mbedtls_test_buffer_free( &buf );
}

void test_test_callback_buffer_wrapper( void ** params )
{

    test_test_callback_buffer( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ), *( (int *) params[7] ), *( (int *) params[8] ) );
}
#line 2085 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_mock_sanity( )
{
    enum { MSGLEN = 105 };
    unsigned char message[MSGLEN];
    unsigned char received[MSGLEN];
    mbedtls_mock_socket socket;

    mbedtls_mock_socket_init( &socket );
    TEST_ASSERT( mbedtls_mock_tcp_send_b( &socket, message, MSGLEN ) < 0 );
    mbedtls_mock_socket_close( &socket );
    mbedtls_mock_socket_init( &socket );
    TEST_ASSERT( mbedtls_mock_tcp_recv_b( &socket, received, MSGLEN ) < 0 );
    mbedtls_mock_socket_close( &socket );

    mbedtls_mock_socket_init( &socket );
    TEST_ASSERT( mbedtls_mock_tcp_send_nb( &socket, message, MSGLEN ) < 0 );
    mbedtls_mock_socket_close( &socket );
    mbedtls_mock_socket_init( &socket );
    TEST_ASSERT( mbedtls_mock_tcp_recv_nb( &socket, received, MSGLEN ) < 0 );
    mbedtls_mock_socket_close( &socket );

exit:

    mbedtls_mock_socket_close( &socket );
}

void test_ssl_mock_sanity_wrapper( void ** params )
{
    (void)params;

    test_ssl_mock_sanity(  );
}
#line 2118 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_mock_tcp( int blocking )
{
    enum { MSGLEN = 105 };
    enum { BUFLEN = MSGLEN / 5 };
    unsigned char message[MSGLEN];
    unsigned char received[MSGLEN];
    mbedtls_mock_socket client;
    mbedtls_mock_socket server;
    size_t written, read;
    int send_ret, recv_ret;
    mbedtls_ssl_send_t *send;
    mbedtls_ssl_recv_t *recv;
    unsigned i;

    if( blocking == 0 )
    {
        send = mbedtls_mock_tcp_send_nb;
        recv = mbedtls_mock_tcp_recv_nb;
    }
    else
    {
        send = mbedtls_mock_tcp_send_b;
        recv = mbedtls_mock_tcp_recv_b;
    }

    mbedtls_mock_socket_init( &client );
    mbedtls_mock_socket_init( &server );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }

    /* Make sure that sending a message takes a few  iterations. */
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server, BUFLEN ) );

    /* Send the message to the server */
    send_ret = recv_ret = 1;
    written = read = 0;
    while( send_ret != 0 || recv_ret != 0 )
    {
        send_ret = send( &client, message + written, MSGLEN - written );

        TEST_ASSERT( send_ret >= 0 );
        TEST_ASSERT( send_ret <= BUFLEN );
        written += send_ret;

        /* If the buffer is full we can test blocking and non-blocking send */
        if ( send_ret == BUFLEN )
        {
            int blocking_ret = send( &client, message , 1 );
            if ( blocking )
            {
                TEST_ASSERT( blocking_ret == 0 );
            }
            else
            {
                TEST_ASSERT( blocking_ret == MBEDTLS_ERR_SSL_WANT_WRITE );
            }
        }

        recv_ret = recv( &server, received + read, MSGLEN - read );

        /* The result depends on whether any data was sent */
        if ( send_ret > 0 )
        {
            TEST_ASSERT( recv_ret > 0 );
            TEST_ASSERT( recv_ret <= BUFLEN );
            read += recv_ret;
        }
        else if( blocking )
        {
            TEST_ASSERT( recv_ret == 0 );
        }
        else
        {
            TEST_ASSERT( recv_ret == MBEDTLS_ERR_SSL_WANT_READ );
            recv_ret = 0;
        }

        /* If the buffer is empty we can test blocking and non-blocking read */
        if ( recv_ret == BUFLEN )
        {
            int blocking_ret = recv( &server, received, 1 );
            if ( blocking )
            {
                TEST_ASSERT( blocking_ret == 0 );
            }
            else
            {
                TEST_ASSERT( blocking_ret == MBEDTLS_ERR_SSL_WANT_READ );
            }
        }
    }
    TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

exit:

    mbedtls_mock_socket_close( &client );
    mbedtls_mock_socket_close( &server );
}

void test_ssl_mock_tcp_wrapper( void ** params )
{

    test_ssl_mock_tcp( *( (int *) params[0] ) );
}
#line 2230 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_mock_tcp_interleaving( int blocking )
{
    enum { ROUNDS = 2 };
    enum { MSGLEN = 105 };
    enum { BUFLEN = MSGLEN / 5 };
    unsigned char message[ROUNDS][MSGLEN];
    unsigned char received[ROUNDS][MSGLEN];
    mbedtls_mock_socket client;
    mbedtls_mock_socket server;
    size_t written[ROUNDS];
    size_t read[ROUNDS];
    int send_ret[ROUNDS];
    int recv_ret[ROUNDS];
    unsigned i, j, progress;
    mbedtls_ssl_send_t *send;
    mbedtls_ssl_recv_t *recv;

    if( blocking == 0 )
    {
        send = mbedtls_mock_tcp_send_nb;
        recv = mbedtls_mock_tcp_recv_nb;
    }
    else
    {
        send = mbedtls_mock_tcp_send_b;
        recv = mbedtls_mock_tcp_recv_b;
    }

    mbedtls_mock_socket_init( &client );
    mbedtls_mock_socket_init( &server );

    /* Fill up the buffers with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < ROUNDS; i++ )
    {
        for( j = 0; j < MSGLEN; j++ )
        {
            message[i][j] = ( i * MSGLEN + j ) & 0xFF;
        }
    }

    /* Make sure that sending a message takes a few  iterations. */
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server, BUFLEN ) );

    /* Send the message from both sides, interleaving. */
    progress = 1;
    for( i = 0; i < ROUNDS; i++ )
    {
        written[i] = 0;
        read[i] = 0;
    }
    /* This loop does not stop as long as there was a successful write or read
     * of at least one byte on either side. */
    while( progress != 0 )
    {
        mbedtls_mock_socket *socket;

        for( i = 0; i < ROUNDS; i++ )
        {
            /* First sending is from the client */
            socket = ( i % 2 == 0 ) ? ( &client ) : ( &server );

            send_ret[i] = send( socket, message[i] + written[i],
                                               MSGLEN - written[i] );
            TEST_ASSERT( send_ret[i] >= 0 );
            TEST_ASSERT( send_ret[i] <= BUFLEN );
            written[i] += send_ret[i];

            /* If the buffer is full we can test blocking and non-blocking
             * send */
            if ( send_ret[i] == BUFLEN )
            {
                int blocking_ret = send( socket, message[i] , 1 );
                if ( blocking )
                {
                    TEST_ASSERT( blocking_ret == 0 );
                }
                else
                {
                    TEST_ASSERT( blocking_ret == MBEDTLS_ERR_SSL_WANT_WRITE );
                }
            }
        }

        for( i = 0; i < ROUNDS; i++ )
        {
            /* First receiving is from the server */
            socket = ( i % 2 == 0 ) ? ( &server ) : ( &client );

            recv_ret[i] = recv( socket, received[i] + read[i],
                                               MSGLEN - read[i] );

            /* The result depends on whether any data was sent */
            if ( send_ret[i] > 0 )
            {
                TEST_ASSERT( recv_ret[i] > 0 );
                TEST_ASSERT( recv_ret[i] <= BUFLEN );
                read[i] += recv_ret[i];
            }
            else if( blocking )
            {
                TEST_ASSERT( recv_ret[i] == 0 );
            }
            else
            {
                TEST_ASSERT( recv_ret[i] == MBEDTLS_ERR_SSL_WANT_READ );
                recv_ret[i] = 0;
            }

            /* If the buffer is empty we can test blocking and non-blocking
             * read */
            if ( recv_ret[i] == BUFLEN )
            {
                int blocking_ret = recv( socket, received[i], 1 );
                if ( blocking )
                {
                    TEST_ASSERT( blocking_ret == 0 );
                }
                else
                {
                    TEST_ASSERT( blocking_ret == MBEDTLS_ERR_SSL_WANT_READ );
                }
            }
        }

        progress = 0;
        for( i = 0; i < ROUNDS; i++ )
        {
            progress += send_ret[i] + recv_ret[i];
        }
    }

    for( i = 0; i < ROUNDS; i++ )
        TEST_ASSERT( memcmp( message[i], received[i], MSGLEN ) == 0 );

exit:

    mbedtls_mock_socket_close( &client );
    mbedtls_mock_socket_close( &server );
}

void test_ssl_mock_tcp_interleaving_wrapper( void ** params )
{

    test_ssl_mock_tcp_interleaving( *( (int *) params[0] ) );
}
#line 2373 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_queue_sanity( )
{
    mbedtls_test_message_queue queue;

    /* Trying to push/pull to an empty queue */
    TEST_ASSERT( mbedtls_test_message_queue_push_info( NULL, 1 )
                 == MBEDTLS_TEST_ERROR_ARG_NULL );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( NULL, 1 )
                 == MBEDTLS_TEST_ERROR_ARG_NULL );

    mbedtls_test_message_queue_setup( &queue, 3 );
    TEST_ASSERT( queue.capacity == 3 );
    TEST_ASSERT( queue.num == 0 );

exit:
    mbedtls_test_message_queue_free( &queue );
}

void test_ssl_message_queue_sanity_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_queue_sanity(  );
}
#line 2393 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_queue_basic( )
{
    mbedtls_test_message_queue queue;

    mbedtls_test_message_queue_setup( &queue, 3 );

    /* Sanity test - 3 pushes and 3 pops with sufficient space */
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 1 ) == 1 );
    TEST_ASSERT( queue.capacity == 3 );
    TEST_ASSERT( queue.num == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 1 ) == 1 );
    TEST_ASSERT( queue.capacity == 3 );
    TEST_ASSERT( queue.num == 2 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 2 ) == 2 );
    TEST_ASSERT( queue.capacity == 3 );
    TEST_ASSERT( queue.num == 3 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 2 ) == 2 );

exit:
    mbedtls_test_message_queue_free( &queue );
}

void test_ssl_message_queue_basic_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_queue_basic(  );
}
#line 2420 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_queue_overflow_underflow( )
{
    mbedtls_test_message_queue queue;

    mbedtls_test_message_queue_setup( &queue, 3 );

    /* 4 pushes (last one with an error), 4 pops (last one with an error) */
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 2 ) == 2 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 3 )
                 == MBEDTLS_ERR_SSL_WANT_WRITE );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 2 ) == 2 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 )
                 == MBEDTLS_ERR_SSL_WANT_READ );

exit:
    mbedtls_test_message_queue_free( &queue );
}

void test_ssl_message_queue_overflow_underflow_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_queue_overflow_underflow(  );
}
#line 2446 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_queue_interleaved( )
{
    mbedtls_test_message_queue queue;

    mbedtls_test_message_queue_setup( &queue, 3 );

    /* Interleaved test - [2 pushes, 1 pop] twice, and then two pops
     * (to wrap around the buffer) */
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 1 ) == 1 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 ) == 1 );

    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 2 ) == 2 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 3 ) == 3 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 1 ) == 1 );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 2 ) == 2 );

    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 5 ) == 5 );
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, 8 ) == 8 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 3 ) == 3 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 5 ) == 5 );

    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, 8 ) == 8 );

exit:
    mbedtls_test_message_queue_free( &queue );
}

void test_ssl_message_queue_interleaved_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_queue_interleaved(  );
}
#line 2480 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_queue_insufficient_buffer( )
{
    mbedtls_test_message_queue queue;
    size_t message_len = 10;
    size_t buffer_len = 5;

    mbedtls_test_message_queue_setup( &queue, 1 );

    /* Popping without a sufficient buffer */
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &queue, message_len )
                 == (int) message_len );
    TEST_ASSERT( mbedtls_test_message_queue_pop_info( &queue, buffer_len )
                 == (int) buffer_len );
exit:
    mbedtls_test_message_queue_free( &queue );
}

void test_ssl_message_queue_insufficient_buffer_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_queue_insufficient_buffer(  );
}
#line 2499 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_uninitialized( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    /* Send with a NULL context */
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( NULL, message, MSGLEN )
                 == MBEDTLS_TEST_ERROR_CONTEXT_ERROR );

    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( NULL, message, MSGLEN )
                 == MBEDTLS_TEST_ERROR_CONTEXT_ERROR );

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 1,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 1,
                                               &client,
                                               &client_context ) == 0 );

    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message, MSGLEN )
                 == MBEDTLS_TEST_ERROR_SEND_FAILED );

    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MBEDTLS_ERR_SSL_WANT_READ );

    /* Push directly to a queue to later simulate a disconnected behavior */
    TEST_ASSERT( mbedtls_test_message_queue_push_info( &server_queue, MSGLEN )
                 == MSGLEN );

    /* Test if there's an error when trying to read from a disconnected
     * socket */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MBEDTLS_TEST_ERROR_RECV_FAILED );
    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_uninitialized_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_uninitialized(  );
}
#line 2543 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_basic( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 1,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 1,
                                               &client,
                                               &client_context ) == 0 );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   MSGLEN ) );

    /* Send the message to the server */
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN ) == MSGLEN );

    /* Read from the server */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MSGLEN );

    TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );
    memset( received, 0, MSGLEN );

    /* Send the message to the client */
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &server_context, message,
                                            MSGLEN ) == MSGLEN );

    /* Read from the client */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &client_context, received, MSGLEN )
                 == MSGLEN );
    TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_basic_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_basic(  );
}
#line 2596 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_queue_overflow_underflow( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 2,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 2,
                                               &client,
                                               &client_context ) == 0 );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   MSGLEN*2 ) );

    /* Send three message to the server, last one with an error */
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN - 1 ) == MSGLEN - 1 );

    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN ) == MSGLEN );

    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN )
                 == MBEDTLS_ERR_SSL_WANT_WRITE );

    /* Read three messages from the server, last one with an error */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received,
                                            MSGLEN - 1 ) == MSGLEN - 1 );

    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MSGLEN );

    TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MBEDTLS_ERR_SSL_WANT_READ );

    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_queue_overflow_underflow_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_queue_overflow_underflow(  );
}
#line 2652 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_socket_overflow( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 2,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 2,
                                               &client,
                                               &client_context ) == 0 );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   MSGLEN ) );

    /* Send two message to the server, second one with an error */
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN ) == MSGLEN );

    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN )
                 == MBEDTLS_TEST_ERROR_SEND_FAILED );

    /* Read the only message from the server */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MSGLEN );

    TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_socket_overflow_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_socket_overflow(  );
}
#line 2699 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_truncated( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 2,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 2,
                                               &client,
                                               &client_context ) == 0 );

    memset( received, 0, MSGLEN );
    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   2 * MSGLEN ) );

    /* Send two messages to the server, the second one small enough to fit in the
     * receiver's buffer. */
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN ) == MSGLEN );
    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN / 2 ) == MSGLEN / 2 );
    /* Read a truncated message from the server */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN/2 )
                 == MSGLEN/2 );

    /* Test that the first half of the message is valid, and second one isn't */
    TEST_ASSERT( memcmp( message, received, MSGLEN/2 ) == 0 );
    TEST_ASSERT( memcmp( message + MSGLEN/2, received + MSGLEN/2, MSGLEN/2 )
                 != 0 );
    memset( received, 0, MSGLEN );

    /* Read a full message from the server */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN/2 )
                 == MSGLEN / 2 );

    /* Test that the first half of the message is valid */
    TEST_ASSERT( memcmp( message, received, MSGLEN/2 ) == 0 );

    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_truncated_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_truncated(  );
}
#line 2756 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_socket_read_error( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 1,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 1,
                                               &client,
                                               &client_context ) == 0 );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   MSGLEN ) );

    TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                            MSGLEN ) == MSGLEN );

    /* Force a read error by disconnecting the socket by hand */
    server.status = 0;
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MBEDTLS_TEST_ERROR_RECV_FAILED );
    /* Return to a valid state */
    server.status = MBEDTLS_MOCK_SOCKET_CONNECTED;

    memset( received, 0, sizeof( received ) );

    /* Test that even though the server tried to read once disconnected, the
     * continuity is preserved */
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MSGLEN );

    TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_socket_read_error_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_socket_read_error(  );
}
#line 2808 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_interleaved_one_way( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 3,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 3,
                                               &client,
                                               &client_context ) == 0 );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   MSGLEN*3 ) );

    /* Interleaved test - [2 sends, 1 read] twice, and then two reads
     * (to wrap around the buffer) */
    for( i = 0; i < 2; i++ )
    {
        TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received,
                                                MSGLEN ) == MSGLEN );
        TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );
        memset( received, 0, sizeof( received ) );
    }

    for( i = 0; i < 2; i++ )
    {
        TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );
    }
    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MBEDTLS_ERR_SSL_WANT_READ );
    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_interleaved_one_way_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_interleaved_one_way(  );
}
#line 2866 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_message_mock_interleaved_two_ways( )
{
    enum { MSGLEN = 10 };
    unsigned char message[MSGLEN], received[MSGLEN];
    mbedtls_mock_socket client, server;
    unsigned i;
    mbedtls_test_message_queue server_queue, client_queue;
    mbedtls_test_message_socket_context server_context, client_context;

    TEST_ASSERT( mbedtls_message_socket_setup( &server_queue, &client_queue, 3,
                                               &server,
                                               &server_context ) == 0 );

    TEST_ASSERT( mbedtls_message_socket_setup( &client_queue, &server_queue, 3,
                                               &client,
                                               &client_context ) == 0 );

    /* Fill up the buffer with structured data so that unwanted changes
     * can be detected */
    for( i = 0; i < MSGLEN; i++ )
    {
        message[i] = i & 0xFF;
    }
    TEST_ASSERT( 0 == mbedtls_mock_socket_connect( &client, &server,
                                                   MSGLEN*3 ) );

    /* Interleaved test - [2 sends, 1 read] twice, both ways, and then two reads
     * (to wrap around the buffer) both ways. */
    for( i = 0; i < 2; i++ )
    {
        TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( mbedtls_mock_tcp_send_msg( &client_context, message,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( mbedtls_mock_tcp_send_msg( &server_context, message,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( mbedtls_mock_tcp_send_msg( &server_context, message,
                                                MSGLEN ) == MSGLEN );

        TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received,
                     MSGLEN ) == MSGLEN );

        TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

        memset( received, 0, sizeof( received ) );

        TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &client_context, received,
                     MSGLEN ) == MSGLEN );

        TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );

        memset( received, 0, sizeof( received ) );
    }

    for( i = 0; i < 2; i++ )
    {
        TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received,
                    MSGLEN ) == MSGLEN );

        TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );
        memset( received, 0, sizeof( received ) );

        TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &client_context, received,
                     MSGLEN ) == MSGLEN );

        TEST_ASSERT( memcmp( message, received, MSGLEN ) == 0 );
        memset( received, 0, sizeof( received ) );
    }

    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &server_context, received, MSGLEN )
                 == MBEDTLS_ERR_SSL_WANT_READ );

    TEST_ASSERT( mbedtls_mock_tcp_recv_msg( &client_context, received, MSGLEN )
                 == MBEDTLS_ERR_SSL_WANT_READ );
    exit:
    mbedtls_message_socket_close( &server_context );
    mbedtls_message_socket_close( &client_context );
}

void test_ssl_message_mock_interleaved_two_ways_wrapper( void ** params )
{
    (void)params;

    test_ssl_message_mock_interleaved_two_ways(  );
}
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#line 2950 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_dtls_replay( data_t * prevs, data_t * new, int ret )
{
    uint32_t len = 0;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;

    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_config_init( &conf );

    TEST_ASSERT( mbedtls_ssl_config_defaults( &conf,
                 MBEDTLS_SSL_IS_CLIENT,
                 MBEDTLS_SSL_TRANSPORT_DATAGRAM,
                 MBEDTLS_SSL_PRESET_DEFAULT ) == 0 );
    TEST_ASSERT( mbedtls_ssl_setup( &ssl, &conf ) == 0 );

    /* Read previous record numbers */
    for( len = 0; len < prevs->len; len += 6 )
    {
        memcpy( ssl.in_ctr + 2, prevs->x + len, 6 );
        mbedtls_ssl_dtls_replay_update( &ssl );
    }

    /* Check new number */
    memcpy( ssl.in_ctr + 2, new->x, 6 );
    TEST_ASSERT( mbedtls_ssl_dtls_replay_check( &ssl ) == ret );

    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_config_free( &conf );
exit:
    ;
}

void test_ssl_dtls_replay_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_ssl_dtls_replay( &data0, &data2, *( (int *) params[4] ) );
}
#endif /* MBEDTLS_SSL_DTLS_ANTI_REPLAY */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#line 2982 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_set_hostname_twice( char *hostname0, char *hostname1 )
{
    mbedtls_ssl_context ssl;
    mbedtls_ssl_init( &ssl );

    TEST_ASSERT( mbedtls_ssl_set_hostname( &ssl, hostname0 ) == 0 );
    TEST_ASSERT( mbedtls_ssl_set_hostname( &ssl, hostname1 ) == 0 );

    mbedtls_ssl_free( &ssl );
exit:
    ;
}

void test_ssl_set_hostname_twice_wrapper( void ** params )
{

    test_ssl_set_hostname_twice( (char *) params[0], (char *) params[1] );
}
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#line 2995 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_crypt_record( int cipher_type, int hash_id,
                       int etm, int tag_mode, int ver,
                       int cid0_len, int cid1_len )
{
    /*
     * Test several record encryptions and decryptions
     * with plenty of space before and after the data
     * within the record buffer.
     */

    int ret;
    int num_records = 16;
    mbedtls_ssl_context ssl; /* ONLY for debugging */

    mbedtls_ssl_transform t0, t1;
    unsigned char *buf = NULL;
    size_t const buflen = 512;
    mbedtls_record rec, rec_backup;

    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_transform_init( &t0 );
    mbedtls_ssl_transform_init( &t1 );
    TEST_ASSERT( build_transforms( &t0, &t1, cipher_type, hash_id,
                                   etm, tag_mode, ver,
                                   (size_t) cid0_len,
                                   (size_t) cid1_len ) == 0 );

    TEST_ASSERT( ( buf = mbedtls_calloc( 1, buflen ) ) != NULL );

    while( num_records-- > 0 )
    {
        mbedtls_ssl_transform *t_dec, *t_enc;
        /* Take turns in who's sending and who's receiving. */
        if( num_records % 3 == 0 )
        {
            t_dec = &t0;
            t_enc = &t1;
        }
        else
        {
            t_dec = &t1;
            t_enc = &t0;
        }

        /*
         * The record header affects the transformation in two ways:
         * 1) It determines the AEAD additional data
         * 2) The record counter sometimes determines the IV.
         *
         * Apart from that, the fields don't have influence.
         * In particular, it is currently not the responsibility
         * of ssl_encrypt/decrypt_buf to check if the transform
         * version matches the record version, or that the
         * type is sensible.
         */

        memset( rec.ctr, num_records, sizeof( rec.ctr ) );
        rec.type    = 42;
        rec.ver[0]  = num_records;
        rec.ver[1]  = num_records;
#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
        rec.cid_len = 0;
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

        rec.buf     = buf;
        rec.buf_len = buflen;
        rec.data_offset = 16;
        /* Make sure to vary the length to exercise different
         * paddings. */
        rec.data_len = 1 + num_records;

        memset( rec.buf + rec.data_offset, 42, rec.data_len );

        /* Make a copy for later comparison */
        rec_backup = rec;

        /* Encrypt record */
        ret = mbedtls_ssl_encrypt_buf( &ssl, t_enc, &rec,
                                       rnd_std_rand, NULL );
        TEST_ASSERT( ret == 0 || ret == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
        if( ret != 0 )
        {
            continue;
        }

        /* Decrypt record with t_dec */
        ret = mbedtls_ssl_decrypt_buf( &ssl, t_dec, &rec );
        TEST_ASSERT( ret == 0 );

        /* Compare results */
        TEST_ASSERT( rec.type == rec_backup.type );
        TEST_ASSERT( memcmp( rec.ctr, rec_backup.ctr, 8 ) == 0 );
        TEST_ASSERT( rec.ver[0] == rec_backup.ver[0] );
        TEST_ASSERT( rec.ver[1] == rec_backup.ver[1] );
        TEST_ASSERT( rec.data_len == rec_backup.data_len );
        TEST_ASSERT( rec.data_offset == rec_backup.data_offset );
        TEST_ASSERT( memcmp( rec.buf + rec.data_offset,
                             rec_backup.buf + rec_backup.data_offset,
                             rec.data_len ) == 0 );
    }

exit:

    /* Cleanup */
    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_transform_free( &t0 );
    mbedtls_ssl_transform_free( &t1 );

    mbedtls_free( buf );
}

void test_ssl_crypt_record_wrapper( void ** params )
{

    test_ssl_crypt_record( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ) );
}
#line 3108 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_crypt_record_small( int cipher_type, int hash_id,
                             int etm, int tag_mode, int ver,
                             int cid0_len, int cid1_len )
{
    /*
     * Test pairs of encryption and decryption with an increasing
     * amount of space in the record buffer - in more detail:
     * 1) Try to encrypt with 0, 1, 2, ... bytes available
     *    in front of the plaintext, and expect the encryption
     *    to succeed starting from some offset. Always keep
     *    enough space in the end of the buffer.
     * 2) Try to encrypt with 0, 1, 2, ... bytes available
     *    at the end of the plaintext, and expect the encryption
     *    to succeed starting from some offset. Always keep
     *    enough space at the beginning of the buffer.
     * 3) Try to encrypt with 0, 1, 2, ... bytes available
     *    both at the front and end of the plaintext,
     *    and expect the encryption to succeed starting from
     *    some offset.
     *
     * If encryption succeeds, check that decryption succeeds
     * and yields the original record.
     */

    mbedtls_ssl_context ssl; /* ONLY for debugging */

    mbedtls_ssl_transform t0, t1;
    unsigned char *buf = NULL;
    size_t const buflen = 256;
    mbedtls_record rec, rec_backup;

    int ret;
    int mode;              /* Mode 1, 2 or 3 as explained above     */
    size_t offset;         /* Available space at beginning/end/both */
    size_t threshold = 96; /* Maximum offset to test against        */

    size_t default_pre_padding  = 64;  /* Pre-padding to use in mode 2  */
    size_t default_post_padding = 128; /* Post-padding to use in mode 1 */

    int seen_success; /* Indicates if in the current mode we've
                       * already seen a successful test. */

    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_transform_init( &t0 );
    mbedtls_ssl_transform_init( &t1 );
    TEST_ASSERT( build_transforms( &t0, &t1, cipher_type, hash_id,
                                   etm, tag_mode, ver,
                                   (size_t) cid0_len,
                                   (size_t) cid1_len ) == 0 );

    TEST_ASSERT( ( buf = mbedtls_calloc( 1, buflen ) ) != NULL );

    for( mode=1; mode <= 3; mode++ )
    {
        seen_success = 0;
        for( offset=0; offset <= threshold; offset++ )
        {
            mbedtls_ssl_transform *t_dec, *t_enc;
            t_dec = &t0;
            t_enc = &t1;

            memset( rec.ctr, offset, sizeof( rec.ctr ) );
            rec.type    = 42;
            rec.ver[0]  = offset;
            rec.ver[1]  = offset;
            rec.buf     = buf;
            rec.buf_len = buflen;
#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
            rec.cid_len = 0;
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

            switch( mode )
            {
                case 1: /* Space in the beginning */
                    rec.data_offset = offset;
                    rec.data_len = buflen - offset - default_post_padding;
                    break;

                case 2: /* Space in the end */
                    rec.data_offset = default_pre_padding;
                    rec.data_len = buflen - default_pre_padding - offset;
                    break;

                case 3: /* Space in the beginning and end */
                    rec.data_offset = offset;
                    rec.data_len = buflen - 2 * offset;
                    break;

                default:
                    TEST_ASSERT( 0 );
                    break;
            }

            memset( rec.buf + rec.data_offset, 42, rec.data_len );

            /* Make a copy for later comparison */
            rec_backup = rec;

            /* Encrypt record */
            ret = mbedtls_ssl_encrypt_buf( &ssl, t_enc, &rec, rnd_std_rand, NULL );

            if( ( mode == 1 || mode == 2 ) && seen_success )
            {
                TEST_ASSERT( ret == 0 );
            }
            else
            {
                TEST_ASSERT( ret == 0 || ret == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
                if( ret == 0 )
                    seen_success = 1;
            }

            if( ret != 0 )
                continue;

            /* Decrypt record with t_dec */
            TEST_ASSERT( mbedtls_ssl_decrypt_buf( &ssl, t_dec, &rec ) == 0 );

            /* Compare results */
            TEST_ASSERT( rec.type == rec_backup.type );
            TEST_ASSERT( memcmp( rec.ctr, rec_backup.ctr, 8 ) == 0 );
            TEST_ASSERT( rec.ver[0] == rec_backup.ver[0] );
            TEST_ASSERT( rec.ver[1] == rec_backup.ver[1] );
            TEST_ASSERT( rec.data_len == rec_backup.data_len );
            TEST_ASSERT( rec.data_offset == rec_backup.data_offset );
            TEST_ASSERT( memcmp( rec.buf + rec.data_offset,
                                 rec_backup.buf + rec_backup.data_offset,
                                 rec.data_len ) == 0 );
        }

        TEST_ASSERT( seen_success == 1 );
    }

exit:

    /* Cleanup */
    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_transform_free( &t0 );
    mbedtls_ssl_transform_free( &t1 );

    mbedtls_free( buf );
}

void test_ssl_crypt_record_small_wrapper( void ** params )
{

    test_ssl_crypt_record_small( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ) );
}
#line 3253 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_tls_prf( int type, data_t * secret, data_t * random,
                  char *label, data_t *result_hex_str, int exp_ret )
{
    unsigned char *output;

    output = mbedtls_calloc( 1, result_hex_str->len );
    if( output == NULL )
        goto exit;

#if defined(MBEDTLS_USE_PSA_CRYPTO)
    TEST_ASSERT( psa_crypto_init() == 0 );
#endif

    TEST_ASSERT( mbedtls_ssl_tls_prf( type, secret->x, secret->len,
                                      label, random->x, random->len,
                                      output, result_hex_str->len ) == exp_ret );

    if( exp_ret == 0 )
    {
        TEST_ASSERT( hexcmp( output, result_hex_str->x,
                     result_hex_str->len, result_hex_str->len ) == 0 );
    }
exit:

    mbedtls_free( output );
}

void test_ssl_tls_prf_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_ssl_tls_prf( *( (int *) params[0] ), &data1, &data3, (char *) params[5], &data6, *( (int *) params[8] ) );
}
#line 3282 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_serialize_session_save_load( int ticket_len, char *crt_file )
{
    mbedtls_ssl_session original, restored;
    unsigned char *buf = NULL;
    size_t len;

    /*
     * Test that a save-load pair is the identity
     */

    mbedtls_ssl_session_init( &original );
    mbedtls_ssl_session_init( &restored );

    /* Prepare a dummy session to work on */
    TEST_ASSERT( ssl_populate_session( &original, ticket_len, crt_file ) == 0 );

    /* Serialize it */
    TEST_ASSERT( mbedtls_ssl_session_save( &original, NULL, 0, &len )
                 == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
    TEST_ASSERT( ( buf = mbedtls_calloc( 1, len ) ) != NULL );
    TEST_ASSERT( mbedtls_ssl_session_save( &original, buf, len, &len )
                 == 0 );

    /* Restore session from serialized data */
    TEST_ASSERT( mbedtls_ssl_session_load( &restored, buf, len) == 0 );

    /*
     * Make sure both session structures are identical
     */
#if defined(MBEDTLS_HAVE_TIME)
    TEST_ASSERT( original.start == restored.start );
#endif
    TEST_ASSERT( original.ciphersuite == restored.ciphersuite );
    TEST_ASSERT( original.compression == restored.compression );
    TEST_ASSERT( original.id_len == restored.id_len );
    TEST_ASSERT( memcmp( original.id,
                         restored.id, sizeof( original.id ) ) == 0 );
    TEST_ASSERT( memcmp( original.master,
                         restored.master, sizeof( original.master ) ) == 0 );

#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_SSL_KEEP_PEER_CERTIFICATE)
    TEST_ASSERT( ( original.peer_cert == NULL ) ==
                 ( restored.peer_cert == NULL ) );
    if( original.peer_cert != NULL )
    {
        TEST_ASSERT( original.peer_cert->raw.len ==
                     restored.peer_cert->raw.len );
        TEST_ASSERT( memcmp( original.peer_cert->raw.p,
                             restored.peer_cert->raw.p,
                             original.peer_cert->raw.len ) == 0 );
    }
#else /* MBEDTLS_SSL_KEEP_PEER_CERTIFICATE */
    TEST_ASSERT( original.peer_cert_digest_type ==
                 restored.peer_cert_digest_type );
    TEST_ASSERT( original.peer_cert_digest_len ==
                 restored.peer_cert_digest_len );
    TEST_ASSERT( ( original.peer_cert_digest == NULL ) ==
                 ( restored.peer_cert_digest == NULL ) );
    if( original.peer_cert_digest != NULL )
    {
        TEST_ASSERT( memcmp( original.peer_cert_digest,
                             restored.peer_cert_digest,
                             original.peer_cert_digest_len ) == 0 );
    }
#endif /* MBEDTLS_SSL_KEEP_PEER_CERTIFICATE */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
    TEST_ASSERT( original.verify_result == restored.verify_result );

#if defined(MBEDTLS_SSL_SESSION_TICKETS) && defined(MBEDTLS_SSL_CLI_C)
    TEST_ASSERT( original.ticket_len == restored.ticket_len );
    if( original.ticket_len != 0 )
    {
        TEST_ASSERT( original.ticket != NULL );
        TEST_ASSERT( restored.ticket != NULL );
        TEST_ASSERT( memcmp( original.ticket,
                             restored.ticket, original.ticket_len ) == 0 );
    }
    TEST_ASSERT( original.ticket_lifetime == restored.ticket_lifetime );
#endif

#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
    TEST_ASSERT( original.mfl_code == restored.mfl_code );
#endif

#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
    TEST_ASSERT( original.trunc_hmac == restored.trunc_hmac );
#endif

#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
    TEST_ASSERT( original.encrypt_then_mac == restored.encrypt_then_mac );
#endif

exit:
    mbedtls_ssl_session_free( &original );
    mbedtls_ssl_session_free( &restored );
    mbedtls_free( buf );
}

void test_ssl_serialize_session_save_load_wrapper( void ** params )
{

    test_ssl_serialize_session_save_load( *( (int *) params[0] ), (char *) params[1] );
}
#line 3383 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_serialize_session_load_save( int ticket_len, char *crt_file )
{
    mbedtls_ssl_session session;
    unsigned char *buf1 = NULL, *buf2 = NULL;
    size_t len0, len1, len2;

    /*
     * Test that a load-save pair is the identity
     */

    mbedtls_ssl_session_init( &session );

    /* Prepare a dummy session to work on */
    TEST_ASSERT( ssl_populate_session( &session, ticket_len, crt_file ) == 0 );

    /* Get desired buffer size for serializing */
    TEST_ASSERT( mbedtls_ssl_session_save( &session, NULL, 0, &len0 )
                 == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );

    /* Allocate first buffer */
    buf1 = mbedtls_calloc( 1, len0 );
    TEST_ASSERT( buf1 != NULL );

    /* Serialize to buffer and free live session */
    TEST_ASSERT( mbedtls_ssl_session_save( &session, buf1, len0, &len1 )
                 == 0 );
    TEST_ASSERT( len0 == len1 );
    mbedtls_ssl_session_free( &session );

    /* Restore session from serialized data */
    TEST_ASSERT( mbedtls_ssl_session_load( &session, buf1, len1 ) == 0 );

    /* Allocate second buffer and serialize to it */
    buf2 = mbedtls_calloc( 1, len0 );
    TEST_ASSERT( buf2 != NULL );
    TEST_ASSERT( mbedtls_ssl_session_save( &session, buf2, len0, &len2 )
                 == 0 );

    /* Make sure both serialized versions are identical */
    TEST_ASSERT( len1 == len2 );
    TEST_ASSERT( memcmp( buf1, buf2, len1 ) == 0 );

exit:
    mbedtls_ssl_session_free( &session );
    mbedtls_free( buf1 );
    mbedtls_free( buf2 );
}

void test_ssl_serialize_session_load_save_wrapper( void ** params )
{

    test_ssl_serialize_session_load_save( *( (int *) params[0] ), (char *) params[1] );
}
#line 3433 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_serialize_session_save_buf_size( int ticket_len, char *crt_file )
{
    mbedtls_ssl_session session;
    unsigned char *buf = NULL;
    size_t good_len, bad_len, test_len;

    /*
     * Test that session_save() fails cleanly on small buffers
     */

    mbedtls_ssl_session_init( &session );

    /* Prepare dummy session and get serialized size */
    TEST_ASSERT( ssl_populate_session( &session, ticket_len, crt_file ) == 0 );
    TEST_ASSERT( mbedtls_ssl_session_save( &session, NULL, 0, &good_len )
                 == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );

    /* Try all possible bad lengths */
    for( bad_len = 1; bad_len < good_len; bad_len++ )
    {
        /* Allocate exact size so that asan/valgrind can detect any overwrite */
        mbedtls_free( buf );
        TEST_ASSERT( ( buf = mbedtls_calloc( 1, bad_len ) ) != NULL );
        TEST_ASSERT( mbedtls_ssl_session_save( &session, buf, bad_len,
                                               &test_len )
                     == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
        TEST_ASSERT( test_len == good_len );
    }

exit:
    mbedtls_ssl_session_free( &session );
    mbedtls_free( buf );
}

void test_ssl_serialize_session_save_buf_size_wrapper( void ** params )
{

    test_ssl_serialize_session_save_buf_size( *( (int *) params[0] ), (char *) params[1] );
}
#line 3469 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_serialize_session_load_buf_size( int ticket_len, char *crt_file )
{
    mbedtls_ssl_session session;
    unsigned char *good_buf = NULL, *bad_buf = NULL;
    size_t good_len, bad_len;

    /*
     * Test that session_load() fails cleanly on small buffers
     */

    mbedtls_ssl_session_init( &session );

    /* Prepare serialized session data */
    TEST_ASSERT( ssl_populate_session( &session, ticket_len, crt_file ) == 0 );
    TEST_ASSERT( mbedtls_ssl_session_save( &session, NULL, 0, &good_len )
                 == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
    TEST_ASSERT( ( good_buf = mbedtls_calloc( 1, good_len ) ) != NULL );
    TEST_ASSERT( mbedtls_ssl_session_save( &session, good_buf, good_len,
                                           &good_len ) == 0 );
    mbedtls_ssl_session_free( &session );

    /* Try all possible bad lengths */
    for( bad_len = 0; bad_len < good_len; bad_len++ )
    {
        /* Allocate exact size so that asan/valgrind can detect any overread */
        mbedtls_free( bad_buf );
        bad_buf = mbedtls_calloc( 1, bad_len ? bad_len : 1 );
        TEST_ASSERT( bad_buf != NULL );
        memcpy( bad_buf, good_buf, bad_len );

        TEST_ASSERT( mbedtls_ssl_session_load( &session, bad_buf, bad_len )
                     == MBEDTLS_ERR_SSL_BAD_INPUT_DATA );
    }

exit:
    mbedtls_ssl_session_free( &session );
    mbedtls_free( good_buf );
    mbedtls_free( bad_buf );
}

void test_ssl_serialize_session_load_buf_size_wrapper( void ** params )
{

    test_ssl_serialize_session_load_buf_size( *( (int *) params[0] ), (char *) params[1] );
}
#line 3511 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_session_serialize_version_check( int corrupt_major,
                                          int corrupt_minor,
                                          int corrupt_patch,
                                          int corrupt_config )
{
    unsigned char serialized_session[ 2048 ];
    size_t serialized_session_len;
    unsigned cur_byte;
    mbedtls_ssl_session session;
    uint8_t should_corrupt_byte[] = { corrupt_major  == 1,
                                      corrupt_minor  == 1,
                                      corrupt_patch  == 1,
                                      corrupt_config == 1,
                                      corrupt_config == 1 };

    mbedtls_ssl_session_init( &session );

    /* Infer length of serialized session. */
    TEST_ASSERT( mbedtls_ssl_session_save( &session,
                                           serialized_session,
                                           sizeof( serialized_session ),
                                           &serialized_session_len ) == 0 );

    mbedtls_ssl_session_free( &session );

    /* Without any modification, we should be able to successfully
     * de-serialize the session - double-check that. */
    TEST_ASSERT( mbedtls_ssl_session_load( &session,
                                           serialized_session,
                                           serialized_session_len ) == 0 );
    mbedtls_ssl_session_free( &session );

    /* Go through the bytes in the serialized session header and
     * corrupt them bit-by-bit. */
    for( cur_byte = 0; cur_byte < sizeof( should_corrupt_byte ); cur_byte++ )
    {
        int cur_bit;
        unsigned char * const byte = &serialized_session[ cur_byte ];

        if( should_corrupt_byte[ cur_byte ] == 0 )
            continue;

        for( cur_bit = 0; cur_bit < CHAR_BIT; cur_bit++ )
        {
            unsigned char const corrupted_bit = 0x1u << cur_bit;
            /* Modify a single bit in the serialized session. */
            *byte ^= corrupted_bit;

            /* Attempt to deserialize */
            TEST_ASSERT( mbedtls_ssl_session_load( &session,
                                                   serialized_session,
                                                   serialized_session_len ) ==
                         MBEDTLS_ERR_SSL_VERSION_MISMATCH );

            /* Undo the change */
            *byte ^= corrupted_bit;
        }
    }

exit:
    ;
}

void test_ssl_session_serialize_version_check_wrapper( void ** params )
{

    test_ssl_session_serialize_version_check( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ) );
}
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#line 3574 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_mbedtls_endpoint_sanity( int endpoint_type )
{
    enum { BUFFSIZE = 1024 };
    mbedtls_endpoint ep;
    int ret = -1;

    ret = mbedtls_endpoint_init( NULL, endpoint_type, MBEDTLS_PK_RSA,
                                 NULL, NULL, NULL );
    TEST_ASSERT( MBEDTLS_ERR_SSL_BAD_INPUT_DATA == ret );

    ret = mbedtls_endpoint_certificate_init( NULL, MBEDTLS_PK_RSA );
    TEST_ASSERT( MBEDTLS_ERR_SSL_BAD_INPUT_DATA == ret );

    ret = mbedtls_endpoint_init( &ep, endpoint_type, MBEDTLS_PK_RSA,
                                 NULL, NULL, NULL );
    TEST_ASSERT( ret == 0 );

exit:
    mbedtls_endpoint_free( &ep, NULL );
}

void test_mbedtls_endpoint_sanity_wrapper( void ** params )
{

    test_mbedtls_endpoint_sanity( *( (int *) params[0] ) );
}
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#line 3597 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_move_handshake_to_state(int endpoint_type, int state, int need_pass)
{
    enum { BUFFSIZE = 1024 };
    mbedtls_endpoint base_ep, second_ep;
    int ret = -1;

    ret = mbedtls_endpoint_init( &base_ep, endpoint_type, MBEDTLS_PK_RSA,
                                 NULL, NULL, NULL );
    TEST_ASSERT( ret == 0 );

    ret = mbedtls_endpoint_init( &second_ep,
                            ( endpoint_type == MBEDTLS_SSL_IS_SERVER ) ?
                            MBEDTLS_SSL_IS_CLIENT : MBEDTLS_SSL_IS_SERVER,
                                 MBEDTLS_PK_RSA, NULL, NULL, NULL );
    TEST_ASSERT( ret == 0 );

    ret = mbedtls_mock_socket_connect( &(base_ep.socket),
                                       &(second_ep.socket),
                                       BUFFSIZE );
    TEST_ASSERT( ret == 0 );

    ret = mbedtls_move_handshake_to_state( &(base_ep.ssl),
                                           &(second_ep.ssl),
                                           state );
    if( need_pass )
    {
        TEST_ASSERT( ret == 0 );
        TEST_ASSERT( base_ep.ssl.state == state );
    }
    else
    {
        TEST_ASSERT( ret != 0 );
        TEST_ASSERT( base_ep.ssl.state != state );
    }

exit:
    mbedtls_endpoint_free( &base_ep, NULL );
    mbedtls_endpoint_free( &second_ep, NULL );
}

void test_move_handshake_to_state_wrapper( void ** params )
{

    test_move_handshake_to_state( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#line 3639 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_handshake_version( int version, int dtls )
{
    handshake_test_options options;
    init_handshake_options( &options );

    options.version = version;
    options.dtls = dtls;
    /* Note - the case below will have to updated, since the test sends no data
     * due to a 1n-1 split against BEAST, that was not expected when preparing
     * the fragment counting code. */
    if( version == MBEDTLS_SSL_MINOR_VERSION_0 ||
        version == MBEDTLS_SSL_MINOR_VERSION_1 )
    {
        options.cli_msg_len = 0;
        options.srv_msg_len = 0;
    }
    perform_handshake( &options );

    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_handshake_version_wrapper( void ** params )
{

    test_handshake_version( *( (int *) params[0] ), *( (int *) params[1] ) );
}
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#line 3663 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_handshake_psk_cipher( char* cipher, int pk_alg, data_t *psk_str, int dtls )
{
    handshake_test_options options;
    init_handshake_options( &options );

    options.cipher = cipher;
    options.dtls = dtls;
    options.psk_str = psk_str;
    options.pk_alg = pk_alg;

    perform_handshake( &options );

    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_handshake_psk_cipher_wrapper( void ** params )
{
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_handshake_psk_cipher( (char *) params[0], *( (int *) params[1] ), &data2, *( (int *) params[4] ) );
}
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#line 3681 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_handshake_cipher( char* cipher, int pk_alg, int dtls )
{
    test_handshake_psk_cipher( cipher, pk_alg, NULL, dtls );

    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_handshake_cipher_wrapper( void ** params )
{

    test_handshake_cipher( (char *) params[0], *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#line 3691 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_app_data( int mfl, int cli_msg_len, int srv_msg_len,
               int expected_cli_fragments,
               int expected_srv_fragments, int dtls )
{
    handshake_test_options options;
    init_handshake_options( &options );

    options.mfl = mfl;
    options.cli_msg_len = cli_msg_len;
    options.srv_msg_len = srv_msg_len;
    options.expected_cli_fragments = expected_cli_fragments;
    options.expected_srv_fragments = expected_srv_fragments;
    options.dtls = dtls;

    perform_handshake( &options );
    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_app_data_wrapper( void ** params )
{

    test_app_data( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ) );
}
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#line 3712 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_app_data_tls( int mfl, int cli_msg_len, int srv_msg_len,
                   int expected_cli_fragments,
                   int expected_srv_fragments )
{
    test_app_data( mfl, cli_msg_len, srv_msg_len, expected_cli_fragments,
                   expected_srv_fragments, 0 );
    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_app_data_tls_wrapper( void ** params )
{

    test_app_data_tls( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#line 3724 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_app_data_dtls( int mfl, int cli_msg_len, int srv_msg_len,
                    int expected_cli_fragments,
                    int expected_srv_fragments )
{
    test_app_data( mfl, cli_msg_len, srv_msg_len, expected_cli_fragments,
                   expected_srv_fragments, 1 );
    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_app_data_dtls_wrapper( void ** params )
{

    test_app_data_dtls( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ) );
}
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#if defined(MBEDTLS_SSL_CONTEXT_SERIALIZATION)
#line 3736 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_handshake_serialization( )
{
    handshake_test_options options;
    init_handshake_options( &options );

    options.serialize = 1;
    options.dtls = 1;
    perform_handshake( &options );
    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_handshake_serialization_wrapper( void ** params )
{
    (void)params;

    test_handshake_serialization(  );
}
#endif /* MBEDTLS_SSL_CONTEXT_SERIALIZATION */
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#if defined(MBEDTLS_DEBUG_C)
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#line 3750 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_handshake_fragmentation( int mfl, int expected_srv_hs_fragmentation, int expected_cli_hs_fragmentation)
{
    handshake_test_options options;
    log_pattern srv_pattern, cli_pattern;

    srv_pattern.pattern = cli_pattern.pattern = "found fragmented DTLS handshake";
    srv_pattern.counter = 0;
    cli_pattern.counter = 0;

    init_handshake_options( &options );
    options.dtls = 1;
    options.mfl = mfl;
    options.srv_auth_mode = MBEDTLS_SSL_VERIFY_REQUIRED;
    options.srv_log_obj = &srv_pattern;
    options.cli_log_obj = &cli_pattern;
    options.srv_log_fun = log_analyzer;
    options.cli_log_fun = log_analyzer;

    perform_handshake( &options );

    /* Test if the server received a fragmented handshake */
    if( expected_srv_hs_fragmentation )
    {
        TEST_ASSERT( srv_pattern.counter >= 1 );
    }
    /* Test if the client received a fragmented handshake */
    if( expected_cli_hs_fragmentation )
    {
        TEST_ASSERT( cli_pattern.counter >= 1 );
    }
exit:
    ;
}

void test_handshake_fragmentation_wrapper( void ** params )
{

    test_handshake_fragmentation( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ) );
}
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */
#endif /* MBEDTLS_DEBUG_C */
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_PKCS1_V15)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_RSA_C)
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#line 3784 "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/tests/suites/test_suite_ssl.function"
void test_renegotiation( int legacy_renegotiation )
{
    handshake_test_options options;
    init_handshake_options( &options );

    options.renegotiate = 1;
    options.legacy_renegotiation = legacy_renegotiation;
    options.dtls = 1;

    perform_handshake( &options );
    /* The goto below is used to avoid an "unused label" warning.*/
    goto exit;
exit:
    ;
}

void test_renegotiation_wrapper( void ** params )
{

    test_renegotiation( *( (int *) params[0] ) );
}
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#endif /* MBEDTLS_ECP_DP_SECP384R1_ENABLED */
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_PKCS1_V15 */
#endif /* !MBEDTLS_USE_PSA_CRYPTO */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#endif /* MBEDTLS_SSL_TLS_C */


#line 49 "suites/main_test.function"


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

#if defined(MBEDTLS_SSL_TLS_C)

        case 0:
            {
                *out_value = MBEDTLS_SSL_IS_CLIENT;
            }
            break;
        case 1:
            {
                *out_value = MBEDTLS_SSL_IS_SERVER;
            }
            break;
        case 2:
            {
                *out_value = MBEDTLS_SSL_HELLO_REQUEST;
            }
            break;
        case 3:
            {
                *out_value = MBEDTLS_SSL_CLIENT_HELLO;
            }
            break;
        case 4:
            {
                *out_value = MBEDTLS_SSL_SERVER_HELLO;
            }
            break;
        case 5:
            {
                *out_value = MBEDTLS_SSL_SERVER_CERTIFICATE;
            }
            break;
        case 6:
            {
                *out_value = MBEDTLS_SSL_SERVER_KEY_EXCHANGE;
            }
            break;
        case 7:
            {
                *out_value = MBEDTLS_SSL_CERTIFICATE_REQUEST;
            }
            break;
        case 8:
            {
                *out_value = MBEDTLS_SSL_SERVER_HELLO_DONE;
            }
            break;
        case 9:
            {
                *out_value = MBEDTLS_SSL_CLIENT_CERTIFICATE;
            }
            break;
        case 10:
            {
                *out_value = MBEDTLS_SSL_CLIENT_KEY_EXCHANGE;
            }
            break;
        case 11:
            {
                *out_value = MBEDTLS_SSL_CERTIFICATE_VERIFY;
            }
            break;
        case 12:
            {
                *out_value = MBEDTLS_SSL_CLIENT_CHANGE_CIPHER_SPEC;
            }
            break;
        case 13:
            {
                *out_value = MBEDTLS_SSL_CLIENT_FINISHED;
            }
            break;
        case 14:
            {
                *out_value = MBEDTLS_SSL_SERVER_CHANGE_CIPHER_SPEC;
            }
            break;
        case 15:
            {
                *out_value = MBEDTLS_SSL_SERVER_FINISHED;
            }
            break;
        case 16:
            {
                *out_value = MBEDTLS_SSL_FLUSH_BUFFERS;
            }
            break;
        case 17:
            {
                *out_value = MBEDTLS_SSL_HANDSHAKE_WRAPUP;
            }
            break;
        case 18:
            {
                *out_value = MBEDTLS_SSL_HANDSHAKE_OVER;
            }
            break;
        case 19:
            {
                *out_value = MBEDTLS_SSL_SERVER_HELLO_VERIFY_REQUEST_SENT;
            }
            break;
        case 20:
            {
                *out_value = MBEDTLS_SSL_SERVER_NEW_SESSION_TICKET;
            }
            break;
        case 21:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_0;
            }
            break;
        case 22:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_1;
            }
            break;
        case 23:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_2;
            }
            break;
        case 24:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_3;
            }
            break;
        case 25:
            {
                *out_value = MBEDTLS_PK_RSA;
            }
            break;
        case 26:
            {
                *out_value = MBEDTLS_PK_ECDSA;
            }
            break;
        case 27:
            {
                *out_value = MBEDTLS_SSL_MAX_FRAG_LEN_512;
            }
            break;
        case 28:
            {
                *out_value = MBEDTLS_SSL_MAX_FRAG_LEN_1024;
            }
            break;
        case 29:
            {
                *out_value = MBEDTLS_SSL_MAX_FRAG_LEN_2048;
            }
            break;
        case 30:
            {
                *out_value = MBEDTLS_SSL_MAX_FRAG_LEN_4096;
            }
            break;
        case 31:
            {
                *out_value = MBEDTLS_SSL_MAX_FRAG_LEN_NONE;
            }
            break;
        case 32:
            {
                *out_value = MBEDTLS_SSL_LEGACY_NO_RENEGOTIATION;
            }
            break;
        case 33:
            {
                *out_value = MBEDTLS_SSL_LEGACY_ALLOW_RENEGOTIATION;
            }
            break;
        case 34:
            {
                *out_value = MBEDTLS_SSL_LEGACY_BREAK_HANDSHAKE;
            }
            break;
        case 35:
            {
                *out_value = -1;
            }
            break;
        case 36:
            {
                *out_value = MBEDTLS_CIPHER_AES_128_CBC;
            }
            break;
        case 37:
            {
                *out_value = MBEDTLS_MD_SHA384;
            }
            break;
        case 38:
            {
                *out_value = MBEDTLS_MD_SHA256;
            }
            break;
        case 39:
            {
                *out_value = MBEDTLS_MD_SHA1;
            }
            break;
        case 40:
            {
                *out_value = MBEDTLS_MD_MD5;
            }
            break;
        case 41:
            {
                *out_value = MBEDTLS_CIPHER_AES_192_CBC;
            }
            break;
        case 42:
            {
                *out_value = MBEDTLS_CIPHER_AES_256_CBC;
            }
            break;
        case 43:
            {
                *out_value = MBEDTLS_CIPHER_ARIA_128_CBC;
            }
            break;
        case 44:
            {
                *out_value = MBEDTLS_CIPHER_ARIA_192_CBC;
            }
            break;
        case 45:
            {
                *out_value = MBEDTLS_CIPHER_ARIA_256_CBC;
            }
            break;
        case 46:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_128_CBC;
            }
            break;
        case 47:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_192_CBC;
            }
            break;
        case 48:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_256_CBC;
            }
            break;
        case 49:
            {
                *out_value = MBEDTLS_CIPHER_BLOWFISH_CBC;
            }
            break;
        case 50:
            {
                *out_value = MBEDTLS_CIPHER_AES_128_GCM;
            }
            break;
        case 51:
            {
                *out_value = MBEDTLS_CIPHER_AES_192_GCM;
            }
            break;
        case 52:
            {
                *out_value = MBEDTLS_CIPHER_AES_256_GCM;
            }
            break;
        case 53:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_128_GCM;
            }
            break;
        case 54:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_192_GCM;
            }
            break;
        case 55:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_256_GCM;
            }
            break;
        case 56:
            {
                *out_value = MBEDTLS_CIPHER_AES_128_CCM;
            }
            break;
        case 57:
            {
                *out_value = MBEDTLS_CIPHER_AES_192_CCM;
            }
            break;
        case 58:
            {
                *out_value = MBEDTLS_CIPHER_AES_256_CCM;
            }
            break;
        case 59:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_128_CCM;
            }
            break;
        case 60:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_192_CCM;
            }
            break;
        case 61:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_256_CCM;
            }
            break;
        case 62:
            {
                *out_value = MBEDTLS_CIPHER_ARC4_128;
            }
            break;
        case 63:
            {
                *out_value = MBEDTLS_CIPHER_NULL;
            }
            break;
        case 64:
            {
                *out_value = MBEDTLS_CIPHER_CHACHA20_POLY1305;
            }
            break;
        case 65:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_NONE;
            }
            break;
        case 66:
            {
                *out_value = MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE;
            }
            break;
        case 67:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_SSL3;
            }
            break;
        case 68:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_TLS1;
            }
            break;
        case 69:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_SHA384;
            }
            break;
        case 70:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_SHA256;
            }
            break;
#endif

#line 78 "suites/main_test.function"
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

#if defined(MBEDTLS_SSL_TLS_C)

        case 0:
            {
#if defined(MBEDTLS_SSL_PROTO_SSL3)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
            {
#if defined(MBEDTLS_RSA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 2:
            {
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 3:
            {
#if defined(MBEDTLS_SSL_PROTO_TLS1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 4:
            {
#if defined(MBEDTLS_CIPHER_MODE_CBC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 5:
            {
#if defined(MBEDTLS_SSL_PROTO_TLS1_1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 6:
            {
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 7:
            {
#if defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 8:
            {
#if defined(MBEDTLS_AES_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 9:
            {
#if defined(MBEDTLS_GCM_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 10:
            {
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 11:
            {
#if defined(MBEDTLS_CCM_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 12:
            {
#if defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 13:
            {
#if defined(MBEDTLS_ECDSA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 14:
            {
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 15:
            {
#if defined(MBEDTLS_CAMELLIA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 16:
            {
#if defined(MBEDTLS_SSL_PROTO_DTLS)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 17:
            {
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 18:
            {
#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 19:
            {
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 20:
            {
#if defined(MBEDTLS_SHA1_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 21:
            {
#if defined(MBEDTLS_MD5_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 22:
            {
#if defined(MBEDTLS_ARIA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 23:
            {
#if defined(MBEDTLS_BLOWFISH_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 24:
            {
#if defined(MBEDTLS_ARC4_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 25:
            {
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 26:
            {
#if defined(MBEDTLS_CHACHAPOLY_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 27:
            {
#if !defined(MBEDTLS_SSL_PROTO_SSL3)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 28:
            {
#if !defined(MBEDTLS_SSL_PROTO_TLS1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 29:
            {
#if !defined(MBEDTLS_SSL_PROTO_TLS1_1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 30:
            {
#if !defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 31:
            {
#if !defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 32:
            {
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 33:
            {
#if defined(MBEDTLS_SSL_CLI_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 34:
            {
#if defined(MBEDTLS_X509_USE_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 35:
            {
#if defined(MBEDTLS_PEM_PARSE_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 36:
            {
#if defined(MBEDTLS_FS_IO)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
#endif

#line 109 "suites/main_test.function"
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

#if defined(MBEDTLS_SSL_TLS_C)
    test_test_callback_buffer_sanity_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_test_callback_buffer_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_mock_sanity_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_mock_tcp_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_mock_tcp_interleaving_wrapper,
#else
    NULL,
#endif
/* Function Id: 5 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_queue_sanity_wrapper,
#else
    NULL,
#endif
/* Function Id: 6 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_queue_basic_wrapper,
#else
    NULL,
#endif
/* Function Id: 7 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_queue_overflow_underflow_wrapper,
#else
    NULL,
#endif
/* Function Id: 8 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_queue_interleaved_wrapper,
#else
    NULL,
#endif
/* Function Id: 9 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_queue_insufficient_buffer_wrapper,
#else
    NULL,
#endif
/* Function Id: 10 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_uninitialized_wrapper,
#else
    NULL,
#endif
/* Function Id: 11 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_basic_wrapper,
#else
    NULL,
#endif
/* Function Id: 12 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_queue_overflow_underflow_wrapper,
#else
    NULL,
#endif
/* Function Id: 13 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_socket_overflow_wrapper,
#else
    NULL,
#endif
/* Function Id: 14 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_truncated_wrapper,
#else
    NULL,
#endif
/* Function Id: 15 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_socket_read_error_wrapper,
#else
    NULL,
#endif
/* Function Id: 16 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_interleaved_one_way_wrapper,
#else
    NULL,
#endif
/* Function Id: 17 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_message_mock_interleaved_two_ways_wrapper,
#else
    NULL,
#endif
/* Function Id: 18 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
    test_ssl_dtls_replay_wrapper,
#else
    NULL,
#endif
/* Function Id: 19 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C)
    test_ssl_set_hostname_twice_wrapper,
#else
    NULL,
#endif
/* Function Id: 20 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_crypt_record_wrapper,
#else
    NULL,
#endif
/* Function Id: 21 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_crypt_record_small_wrapper,
#else
    NULL,
#endif
/* Function Id: 22 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_tls_prf_wrapper,
#else
    NULL,
#endif
/* Function Id: 23 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_serialize_session_save_load_wrapper,
#else
    NULL,
#endif
/* Function Id: 24 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_serialize_session_load_save_wrapper,
#else
    NULL,
#endif
/* Function Id: 25 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_serialize_session_save_buf_size_wrapper,
#else
    NULL,
#endif
/* Function Id: 26 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_serialize_session_load_buf_size_wrapper,
#else
    NULL,
#endif
/* Function Id: 27 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_session_serialize_version_check_wrapper,
#else
    NULL,
#endif
/* Function Id: 28 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15)
    test_mbedtls_endpoint_sanity_wrapper,
#else
    NULL,
#endif
/* Function Id: 29 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15)
    test_move_handshake_to_state_wrapper,
#else
    NULL,
#endif
/* Function Id: 30 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
    test_handshake_version_wrapper,
#else
    NULL,
#endif
/* Function Id: 31 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2)
    test_handshake_psk_cipher_wrapper,
#else
    NULL,
#endif
/* Function Id: 32 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2)
    test_handshake_cipher_wrapper,
#else
    NULL,
#endif
/* Function Id: 33 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
    test_app_data_wrapper,
#else
    NULL,
#endif
/* Function Id: 34 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
    test_app_data_tls_wrapper,
#else
    NULL,
#endif
/* Function Id: 35 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) && defined(MBEDTLS_SSL_PROTO_DTLS)
    test_app_data_dtls_wrapper,
#else
    NULL,
#endif
/* Function Id: 36 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) && defined(MBEDTLS_SSL_PROTO_DTLS) && defined(MBEDTLS_SSL_RENEGOTIATION) && defined(MBEDTLS_SSL_CONTEXT_SERIALIZATION)
    test_handshake_serialization_wrapper,
#else
    NULL,
#endif
/* Function Id: 37 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) && defined(MBEDTLS_DEBUG_C) && defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
    test_handshake_fragmentation_wrapper,
#else
    NULL,
#endif
/* Function Id: 38 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C) && !defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_PKCS1_V15) && defined(MBEDTLS_SSL_PROTO_TLS1_2) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) && defined(MBEDTLS_SSL_PROTO_DTLS) && defined(MBEDTLS_SSL_RENEGOTIATION)
    test_renegotiation_wrapper,
#else
    NULL,
#endif

#line 138 "suites/main_test.function"
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
    const char *default_filename = "./test_suite_ssl.datax";
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
                    mbedtls_fprintf( stdout, "  %s\n  at line %d, %s\n",
                                     test_info.test, test_info.line_no,
                                     test_info.filename );
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


#line 234 "suites/main_test.function"

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
