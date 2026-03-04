const Usuario = require('../models/usuario');
const bcrypt = require('bcrypt');

class UsuarioService {
  async cadastrar(dto) {
    // Verifica se usuário já existe pelo email
    const usuarioExistente = await Usuario.findOne({ where: { email: dto.email } });
    if (usuarioExistente) {
      throw new Error('Usuário já cadastrado');
    }

    // Criptografa a senha antes de salvar
    const senhaHash = await bcrypt.hash(dto.senha, 10);

    // Cria o usuário
    const usuario = await Usuario.create({
      nome: dto.nome,
      email: dto.email,
      senha: senhaHash
    });

    // Retorna dados sem a senha
    return {
      id: usuario.id,
      nome: usuario.nome,
      email: usuario.email
    };
  }
}

module.exports = new UsuarioService();
