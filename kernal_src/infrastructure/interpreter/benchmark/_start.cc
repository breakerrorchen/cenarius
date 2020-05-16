
#include <iostream>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <atomic>
#include <functional>
#include "interpreter.h"
using namespace interpreter;

// #define OneArgument(a) printf("guodong 1\n");
// #define TwoArguments(a, b) printf("guodong 2\n");
 
// #define GetMacro(_1, _2, NAME, ...) NAME
// #define Macro(...) GetMacro(__VA_ARGS__, TwoArguments, OneArgument, ...)(__VA_ARGS__)
 
// usage:


class a {
public:
    a() {
        printf("a\n");
    }
    virtual ~a() {
        printf("~a\n");
    }
    void print(i_parameter& parmer) {
        if (parmer.get_argument_count() > 0) {
            auto v = parmer[0];
            auto object = v.to_object();
            auto v0 = (js_value)object["a"];
            printf("%s \n", v0.to_json_string().c_str());
        }
    }
};


void haha(i_parameter& parmer) {
    printf("%s %d\n", __FILE__, __LINE__);
}

int main() {
    // Macro(a); // OneArument(a) is called
    // Macro(a, b);  // TwoArguments(a, b) is called

    i_initializer::start();
    i_vm vm;
    i_release_scope scope(vm);
    i_class a_class(vm);
    a_class.constructor(_I_BIND(a));
    a_class.function("print", _I_BIND(a, print));
    a_class.build();

    i_actuator actuator(vm, a_class);
    auto context = actuator.get_context();
    auto gg = context.get_global_object();
    gg.hold_native_data(i_runtime_container<a>::create());
    gg["guodong"] = i_value::create(context, false);
    gg["haha"] = i_value::create(context, _I_BIND_FUNCTION(haha));

    context.eval("print({a:1}); haha()");
    return 0;
}