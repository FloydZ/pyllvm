#include <llvm/PassInfo.h>
#include "Support/raw_py_binaryio_ostream.hpp"
#include "../init.hpp"
#include "../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::PassInfo> : pybinder_t {
        using binding_t = py::class_<llvm::PassInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.PassInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "PassInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("PassInfo").cast<binding_t>()
				//.def(py::init<>())
                .def("getPassName", &llvm::PassInfo::getPassName);
        }
    };


    static class_pybinder_t<llvm::PassInfo> PYLLVM_UNIQUE_NAME(_);
}
