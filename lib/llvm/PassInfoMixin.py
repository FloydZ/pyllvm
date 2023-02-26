from typing import Any, Optional, TypeVar, Generic

T = TypeVar('T')
class PassInfoMixin(Generic[T]):

    def __hash__(self) -> int:
        pass

    def __init__(self) -> None:
        pass
    
    def name() -> str:
        pass
