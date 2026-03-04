// Função para validar CPF localmente (dígitos verificadores)
function validarCPF(cpf) {
  cpf = cpf.replace(/\D/g, '');
  if (cpf.length !== 11 || /^(\d)\1{10}$/.test(cpf)) return false;

  let soma = 0;
  for (let i = 0; i < 9; i++) soma += parseInt(cpf.charAt(i)) * (10 - i);
  let resto = (soma * 10) % 11;
  if (resto === 10 || resto === 11) resto = 0;
  if (resto !== parseInt(cpf.charAt(9))) return false;

  soma = 0;
  for (let i = 0; i < 10; i++) soma += parseInt(cpf.charAt(i)) * (11 - i);
  resto = (soma * 10) % 11;
  if (resto === 10 || resto === 11) resto = 0;
  if (resto !== parseInt(cpf.charAt(10))) return false;

  return true;
}

document.getElementById('validar').addEventListener('click', async () => {
  const cpfInput = document.getElementById('cpf').value.trim();
  const resultadoDiv = document.getElementById('resultado');
  resultadoDiv.textContent = '';

  if (!validarCPF(cpfInput)) {
    resultadoDiv.textContent = 'CPF inválido localmente.';
    resultadoDiv.style.color = 'red';
    return;
  }

  resultadoDiv.textContent = 'Validando CPF na Receita Federal...';
  resultadoDiv.style.color = 'black';

  try {
    //URL da API
    const response = await fetch(`https://api.exemplo-validacao-cpf.com/consulta?cpf=${cpfInput}`, {
      method: 'GET',
      headers: {
        'Accept': 'application/json',
        // 'Authorization': 'Bearer SEU_TOKEN_AQUI' // se necessário apenas
      }
    });

    if (!response.ok) {
      throw new Error('Erro na consulta da API');
    }

    const data = await response.json();

    // Resposta esperada: { status: "Regular", nome: "Fulano de Tal", cpf: "[]" }
    if (data.status === 'Regular') {
      resultadoDiv.textContent = `CPF válido e ativo. Nome: ${data.nome}`;
      resultadoDiv.style.color = 'green';
    } else {
      resultadoDiv.textContent = `CPF com situação: ${data.status}`;
      resultadoDiv.style.color = 'orange';
    }
  } catch (error) {
    resultadoDiv.textContent = `Erro ao consultar API: ${error.message}`;
    resultadoDiv.style.color = 'red';
  }
});
