#include <boost/test/unit_test.hpp>
#include <eosio/testing/tester.hpp>

#include <multi_index_test/multi_index_test.wast.hpp>
#include <multi_index_test/multi_index_test.abi.hpp>

#include <Runtime/Runtime.h>

#include <fc/variant_object.hpp>
#include <fc/io/json.hpp>


#ifdef NON_VALIDATING_TEST
#define TESTER tester
#else
#define TESTER validating_tester
#endif

using namespace eosio::testing;

