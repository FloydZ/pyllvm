from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class IntRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper) -> IntRecTy:
        pass
