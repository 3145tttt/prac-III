#include "2.cpp"
#include <vector>
#include <map>
#include <iostream>
#include <functional>

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z){
        const size_t N = args.size();
        complex_stack main_stack;
        std::map<std::string, std::function <void(complex_stack &stack)> > str_to_op;

        str_to_op.emplace("+", [](complex_stack &stack) {
            stack = ~~stack << (+~stack + +stack);
        });

        str_to_op.emplace("-", [](complex_stack &stack) {
            stack = ~~stack << (+~stack - +stack);
        });

        str_to_op.emplace("*", [](complex_stack &stack) {
            stack = ~~stack << (+~stack * +stack);
        });

        str_to_op.emplace("/", [](complex_stack &stack) {
            stack = ~~stack << (+~stack / +stack);
        });

        str_to_op.emplace("!", [](complex_stack &stack) {
            stack = stack << +stack;
        });

        str_to_op.emplace(";", [](complex_stack &stack) {
            stack = ~stack;
        });

        str_to_op.emplace("~", [](complex_stack &stack) {
            stack = ~stack << ~(+stack);
        });

        str_to_op.emplace("#", [](complex_stack &stack) {
            stack = ~stack << -(+stack);
        });

        for(size_t i = 0; i < N; ++i) {
            if(args[i][0] == '('){
                main_stack = main_stack << complex(args[i]);
            } else if(args[i] == "z"){
                main_stack = main_stack << z;
            } else {
                str_to_op[args[i]](main_stack);
            }
        }

        return +main_stack;
    }
}