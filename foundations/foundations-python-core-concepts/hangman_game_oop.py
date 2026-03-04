from __future__ import annotations
import random
from typing import List, Set


class JogoDaForca:
    """Classe encapsulando toda a lógica do Jogo da Forca."""

    ESTAGIOS: List[str] = [
        """
           ------
           |    |
                |
                |
                |
                |
        =========
        """,
        """
           ------
           |    |
           O    |
                |
                |
                |
        =========
        """,
        """
           ------
           |    |
           O    |
           |    |
                |
                |
        =========
        """,
        """
           ------
           |    |
           O    |
          /|    |
                |
                |
        =========
        """,
        """
           ------
           |    |
           O    |
          /|\\   |
                |
                |
        =========
        """,
        """
           ------
           |    |
           O    |
          /|\\   |
          /     |
                |
        =========
        """,
        """
           ------
           |    |
           O    |
          /|\\   |
          / \\   |
                |
        =========
        """,
    ]

    def __init__(self, palavras: List[str] = None, max_erros: int = 6) -> None:
        self.palavras: List[str] = palavras or ['python', 'programacao', 'computador', 'jogo', 'forca']
        self.max_erros: int = max_erros
        self.palavra_secreta: str = self.escolher_palavra()
        self.letras_adivinhadas: Set[str] = set()
        self.letras_erradas: Set[str] = set()
        self.erros: int = 0

    # --------------------------
    # Lógica do jogo
    # --------------------------
    def escolher_palavra(self) -> str:
        return random.choice(self.palavras)

    def mostrar_palavra(self) -> str:
        return ' '.join([letra if letra in self.letras_adivinhadas else '_' for letra in self.palavra_secreta])

    def desenhar_forca(self) -> None:
        print(self.ESTAGIOS[self.erros])

    def solicitar_letra(self) -> str:
        while True:
            letra = input("Digite uma letra: ").lower().strip()
            if len(letra) != 1 or not letra.isalpha():
                print("Por favor, digite apenas uma letra válida.")
            elif letra in self.letras_adivinhadas or letra in self.letras_erradas:
                print("Você já tentou essa letra. Tente outra.")
            else:
                return letra

    def letra_correta(self, letra: str) -> bool:
        return letra in self.palavra_secreta

    def venceu(self) -> bool:
        return all(letra in self.letras_adivinhadas for letra in self.palavra_secreta)

    # --------------------------
    # Execução
    # --------------------------
    def jogar(self) -> None:
        print("=== Bem-vindo ao Jogo da Forca! ===")

        while self.erros < self.max_erros:
            print("\nPalavra:", self.mostrar_palavra())
            print(f"Tentativas restantes: {self.max_erros - self.erros}")
            self.desenhar_forca()
            if self.letras_erradas:
                print("Letras incorretas:", ', '.join(sorted(self.letras_erradas)))

            letra = self.solicitar_letra()

            if self.letra_correta(letra):
                self.letras_adivinhadas.add(letra)
                print("Letra correta!")
            else:
                self.letras_erradas.add(letra)
                self.erros += 1
                print("Letra incorreta!")

            if self.venceu():
                print("\nParabéns! Você ganhou!")
                print("A palavra era:", self.palavra_secreta)
                break
        else:
            self.desenhar_forca()
            print("\nVocê perdeu! Suas tentativas acabaram.")
            print("A palavra era:", self.palavra_secreta)


def main() -> None:
    jogo = JogoDaForca()
    jogo.jogar()


if __name__ == "__main__":
    main()