import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.preprocessing import LabelEncoder
import matplotlib.pyplot as plt
import seaborn as sns

def main():
    # Criar dataset fictício
    data = pd.DataFrame({
        'idade': [25, 45, 30, 50, 23, 40, 60, 35, 28, 42],
        'tempo_contrato': [12, 24, 6, 36, 3, 18, 48, 9, 15, 30],
        'plano': ['básico', 'premium', 'padrão', 'premium', 'básico', 'padrão', 'premium', 'básico', 'padrão', 'premium'],
        'uso_dados_gb': [2.5, 10, 5, 12, 1, 6, 15, 3, 7, 11],
        'chamadas_suporte': [1, 0, 2, 1, 3, 1, 0, 2, 1, 0],
        'churn': [0, 0, 1, 0, 1, 0, 0, 1, 0, 0]
    })

    # Pré-processamento
    le = LabelEncoder()
    data['plano'] = le.fit_transform(data['plano'])

    X = data.drop('churn', axis=1)
    y = data['churn']

    # Divisão treino/teste
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # Treinamento
    model = RandomForestClassifier(random_state=42)
    model.fit(X_train, y_train)

    # Avaliação
    y_pred = model.predict(X_test)
    print("Matriz de Confusão:")
    print(confusion_matrix(y_test, y_pred))
    print("\nRelatório de Classificação:")
    print(classification_report(y_test, y_pred))

    # Importância das variáveis
    importances = model.feature_importances_
    features = X.columns
    for feature, importance in zip(features, importances):
        print(f"{feature}: {importance:.3f}")

    # Visualização da importância
    plt.figure(figsize=(8,5))
    sns.barplot(x=importances, y=features)
    plt.title('Importância das Variáveis')
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()
