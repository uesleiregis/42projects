
# Type Hint

def somar(a: int, b: int) -> int:
    return a + b

def dar_oi(nome: str) -> None:
    print(f"Olá {str}!")

# Tipo any para indicar flexibilidade total
from typing import Any
def printar_valores(valor: Any, Valor2: Any) -> None:
    print(valor1)
    print(valor2)



#Type Hints para Classes e Métodos
# anotação de tipos para classes  e métodos
from typing import ClassVar

class Carro:
    assentos: ClassVar[int] = 4 # Variável de classe
    cor: str

    def __init__(self, cor: str) -> None:
        self.cor = cor