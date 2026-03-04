from __future__ import annotations
from typing import Callable, Optional


class Calculadora:
    """Calculadora orientada a objetos com operações básicas e tratamento robusto."""

    def __init__(self) -> None:
        self.operacoes: dict[str, Callable[[float, float], float]] = {
            '+': self.adicionar,
            '-': self.subtrair,
            '*': self.multiplicar,
            '/': self.dividir,
        }
        self.historico: list[str] = []

    # --------------------------
    # Operações
    # --------------------------
    @staticmethod
    def adicionar(a: float, b: float) -> float:
        return a + b

    @staticmethod
    def subtrair(a: float, b: float) -> float:
        return a - b

    @staticmethod
    def multiplicar(a: float, b: float) -> float:
        return a * b

    @staticmethod
    def dividir(a: float, b: float) -> float:
        if b == 0:
            raise ZeroDivisionError("Divisão por zero não é permitida.")
        return a / b

    # --------------------------
    # Entrada do usuário
    # --------------------------
    @staticmethod
    def obter_numero(prompt: str) -> float:
        while True:
            entrada = input(prompt).strip()
            try:
                return float(entrada)
            except ValueError:
                print("Entrada inválida! Por favor, digite um número válido.")

    def obter_operacao(self) -> Optional[str]:
        while True:
            op = input("Escolha uma operação (+, -, *, /) ou 's' para sair: ").strip()
            if op.lower() == 's':
                return None
            if op in self.operacoes:
                return op
            print("Operação inválida! Tente novamente.")

    # --------------------------
    # Execução
    # --------------------------
    def executar(self) -> None:
        print("=== Calculadora Profissional em Python ===")
        while True:
            operacao = self.obter_operacao()
            if operacao is None:
                print("Encerrando a calculadora. Até logo!")
                break

            num1 = self.obter_numero("Digite o primeiro número: ")
            num2 = self.obter_numero("Digite o segundo número: ")

            try:
                func = self.operacoes[operacao]
                resultado = func(num1, num2)
            except ZeroDivisionError as e:
                print(f"Erro: {e}\n")
                continue

            expressao = f"{num1} {operacao} {num2} = {resultado}"
            print(f"Resultado: {expressao}\n")
            self.historico.append(expressao)

    # --------------------------
    # Histórico (opcional)
    # --------------------------
    def mostrar_historico(self) -> None:
        if not self.historico:
            print("Nenhuma operação realizada ainda.")
            return
        print("\n=== Histórico de Operações ===")
        for idx, item in enumerate(self.historico, start=1):
            print(f"{idx}: {item}")
        print()


if __name__ == "__main__":
    calc = Calculadora()
    calc.executar()
    # calc.mostrar_historico()  # Descomente se quiser exibir histórico no final