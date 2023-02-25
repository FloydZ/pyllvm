#!/usr/bin/env python3
import typing
import sys

import pyllvm
import pyllvm.llvm as llvm

def diagnoses_handler(diag: llvm.SMDiagnostic, user_ctx: typing.Any):
    diag.print(__name__, sys.stderr.buffer)

record_keeper = llvm.RecordKeeper()
source_manager = llvm.SourceMgr()

passInfo = llvm.PassInfo()

source_manager.setDiagHandler(diagnoses_handler, None)
source_manager.setIncludeDirs([
    '/usr/include/llvm/include',
    '/usr/include/llvm/lib/Target/X86',
])
#
#buf = llvm.MemoryBuffer.getFile("/home/duda/Downloads/compiler/clang/llvm/lib/Target/X86/X86.td", True)
#assert not buf.isEmpty()
#
#source_manager.AddNewSourceBuffer(buf, llvm.SMLoc())
#
#failed = llvm.TableGenParseFile(source_manager, record_keeper)
#if not failed:
#    r_insts = record_keeper.getAllDerivedDefinitions("X86Inst")
#    print(r_insts[0].getName())
#    print(r_insts[1].getName())
#    print(r_insts[2].getName())
