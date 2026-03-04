from __future__ import annotations
import csv
from typing import List
from statistics import mean

class CSVEstatisticas:
    """Classe para ler CSV e gerar resumos estatísticos."""

    def __init__(self, caminho: str, delimitador: str = ',', tem_cabecalho: bool = True) -> None:
        self.caminho: str = caminho
        self.delimitador: str = delimitador
        self.tem_cabecalho: bool = tem_cabecalho
        self.conteudo: List[List[str]] = []
        self.colunas: List[str] = []

    def ler_csv(self) -> bool:
        """Lê o arquivo CSV e armazena o conteúdo."""
        try:
            with open(self.caminho, 'r', encoding='utf-8') as arquivo:
                leitor = csv.reader(arquivo, delimiter=self.delimitador)
                linhas = list(leitor)
                if not linhas:
                    print("Arquivo vazio!")
                    return False
                if self.tem_cabecalho:
                    self.colunas = linhas[0]
                    self.conteudo = linhas[1:]
                else:
                    self.colunas = [f"Coluna {i+1}" for i in range(len(linhas[0]))]
                    self.conteudo = linhas
            return True
        except FileNotFoundError:
            print(f"Erro: Arquivo '{self.caminho}' não encontrado!")
            return False
        except Exception as e:
            print(f"Erro inesperado: {e}")
            return False

    def gerar_resumo(self) -> None:
        """Exibe resumo estatístico do CSV."""
        if not self.conteudo:
            print("Nenhum conteúdo para análise.")
            return

        num_linhas = len(self.conteudo)
        num_colunas = len(self.colunas)
        print("\n" + "="*60)
        print(f"Resumo do arquivo: {self.caminho}")
        print(f"Linhas: {num_linhas}, Colunas: {num_colunas}")
        print("Colunas:", ', '.join(self.colunas))
        print("="*60)

        # Transpor conteúdo para trabalhar por coluna
        col_data: List[List[str]] = [[] for _ in range(num_colunas)]
        for linha in self.conteudo:
            for idx, valor in enumerate(linha):
                col_data[idx].append(valor)

        # Análise estatística de colunas numéricas
        for idx, valores in enumerate(col_data):
            nome_col = self.colunas[idx]
            numericos: List[float] = []
            for v in valores:
                try:
                    numericos.append(float(v))
                except ValueError:
                    continue  # Ignora valores não numéricos

            if numericos:
                minimo = min(numericos)
                maximo = max(numericos)
                media = mean(numericos)
                soma = sum(numericos)
                print(f"\nColuna: {nome_col} (numérica)")
                print(f"  Valores válidos: {len(numericos)} / {len(valores)}")
                print(f"  Mínimo: {minimo}")
                print(f"  Máximo: {maximo}")
                print(f"  Média: {media:.2f}")
                print(f"  Soma: {soma}")
            else:
                print(f"\nColuna: {nome_col} (não numérica)")

        print("\nAnálise concluída!\n")


def main() -> None:
    caminho = input("Digite o caminho/nome do arquivo CSV: ").strip()
    delimitador = input("Digite o delimitador do CSV (padrão é ','): ").strip() or ','
    tem_cabecalho_input = input("O arquivo possui cabeçalho? (s/n, padrão s): ").strip().lower() or 's'
    tem_cabecalho = tem_cabecalho_input == 's'

    csv_stats = CSVEstatisticas(caminho, delimitador, tem_cabecalho)
    if csv_stats.ler_csv():
        csv_stats.gerar_resumo()


if __name__ == "__main__":
    main()