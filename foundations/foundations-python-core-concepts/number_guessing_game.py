from __future__ import annotations
import random
from typing import Optional, List


class JogoAdivinhacao:
    """Classe encapsulando toda a lógica do jogo da adivinhação."""

    def __init__(self, num_maximo: int = 100, num_tentativas: int = 5) -> None:
        self.num_maximo: int = num_maximo
        self.num_tentativas: int = num_tentativas
        self.numero_secreto: int = random.randint(1, self.num_maximo)
        self.palpites: List[int] = []

    def obter_palpite(self) -> int:
        """Solicita e valida o palpite do usuário dentro do intervalo permitido."""
        while True:
            entrada = input(f"Digite um número entre 1 e {self.num_maximo}: ").strip()
            try:
                palpite = int(entrada)
                if 1 <= palpite <= self.num_maximo:
                    if palpite in self.palpites:
                        print("Você já tentou esse número. Tente outro.")
                    else:
                        self.palpites.append(palpite)
                        return palpite
                else:
                    print(f"Por favor, digite um número dentro do intervalo de 1 a {self.num_maximo}.")
            except ValueError:
                print("Entrada inválida! Por favor, digite um número inteiro.")

    def jogar(self) -> None:
        """Executa o loop principal do jogo."""
        print(f"\n🎯 Bem-vindo ao Jogo da Adivinhação!")
        print(f"Você tem {self.num_tentativas} tentativas para adivinhar o número secreto entre 1 e {self.num_maximo}.\n")

        for tentativa in range(1, self.num_tentativas + 1):
            print(f"Tentativa {tentativa} de {self.num_tentativas}")
            palpite = self.obter_palpite()

            if palpite == self.numero_secreto:
                print(f"🎉 Parabéns! Você acertou o número secreto {self.numero_secreto} na tentativa {tentativa}!\n")
                return
            elif palpite < self.numero_secreto:
                print("Dica: O número secreto é maior.\n")
            else:
                print("Dica: O número secreto é menor.\n")

            tentativas_restantes = self.num_tentativas - tentativa
            if tentativas_restantes > 0:
                print(f"Tentativas restantes: {tentativas_restantes}\n")
            else:
                print(f"😞 Que pena, você perdeu. O número secreto era {self.numero_secreto}.\n")

    def jogar_novamente(self) -> bool:
        """Pergunta ao usuário se deseja jogar novamente."""
        resposta = input("Quer jogar novamente? (s/n): ").strip().lower()
        return resposta == 's'


def main() -> None:
    """Função principal controlando o fluxo do jogo."""
    while True:
        jogo = JogoAdivinhacao()
        jogo.jogar()
        if not jogo.jogar_novamente():
            print("Obrigado por jogar! Até a próxima!")
            break


if __name__ == "__main__":
    main()