new Vue({
  el: '#app',
  data() {
    return {
      cep: '',
      cepData: null,
    };
  },
  methods: {
    consultaCep() {
      const cepValido = /^\d{8}$/;
      if (!cepValido.test(this.cep)) {
        alert('Por favor, insira um CEP válido com 8 dígitos numéricos.');
        this.cepData = null;
        return;
      }

      axios
        .get(`https://viacep.com.br/ws/${this.cep}/json/`)
        .then((response) => {
          if (response.data.erro) {
            alert('CEP não encontrado.');
            this.cepData = null;
          } else {
            this.cepData = response.data;
          }
        })
        .catch((error) => {
          console.error('Erro ao consultar o CEP:', error);
          alert('Erro ao consultar o CEP. Tente novamente mais tarde.');
          this.cepData = null;
        });
    },
  },
});
