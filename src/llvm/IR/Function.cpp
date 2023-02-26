#include <llvm/IR/Function.h>
#include "../../init.hpp"
#include "../../macro.hpp"


namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::Function> : pybinder_t {
        using binding_t = py::class_<llvm::Function, std::unique_ptr<llvm::Function, py::nodelete>>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Function"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "Function" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("Function").cast<binding_t>()
                .def("hasLazyArguments", &llvm::Function::hasLazyArguments)
                .def("getFunction", &llvm::Function::getFunction)
                .def("getInstructionCount", &llvm::Function::getInstructionCount)
                .def("isVarArg", &llvm::Function::isVarArg)
                .def("isMaterializable", &llvm::Function::isMaterializable)
                ;
        }
    };

    static class_pybinder_t<llvm::Function> PYLLVM_UNIQUE_NAME(_);
}
