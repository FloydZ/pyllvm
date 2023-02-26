#include <llvm/IR/PassManager.h>
#include <llvm/IR/Function.h>
#include "../Support/raw_py_binaryio_ostream.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<class DerivedT>
    struct class_pybinder_t<llvm::PassInfoMixin<DerivedT>> : pybinder_t {
        using binding_t = py::class_<llvm::PassInfoMixin<DerivedT>>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.PassInfoMixin"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "PassInfoMixin" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("PassInfoMixin").cast<binding_t>()
				.def(py::init<>())
                .def("name", &llvm::PassInfoMixin<DerivedT>::getPassName);
        }
    };

    template<typename IRUnitT, typename ...ExtraArgsTs>
    struct class_pybinder_t<llvm::AnalysisManager<IRUnitT, ExtraArgsTs...>> : pybinder_t {
        using binding_t = py::class_<llvm::AnalysisManager<IRUnitT, ExtraArgsTs...>>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AnalysisManager"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AnalysisManager" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("AnalysisManager").cast<binding_t>()
				.def(py::init<>())
//.def("empty", &llvm::AnalysisManager<IRUnitT, ExtraArgsTs...>::empty)
                .def("clear", &llvm::AnalysisManager<IRUnitT, ExtraArgsTs...>::clear);
        }
    };
    static class_pybinder_t<llvm::AnalysisManager<llvm::Function>> PYLLVM_UNIQUE_NAME(_);
}
