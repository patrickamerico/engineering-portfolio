const { Model, DataTypes } = require('sequelize');
const sequelize = require('../database'); // instância do Sequelize configurada

class Usuario extends Model {}

Usuario.init({
  nome: {
    type: DataTypes.STRING,
    allowNull: false
  },
  email: {
    type: DataTypes.STRING,
    allowNull: false,
    unique: true,
    validate: { isEmail: true }
  },
  senha: {
    type: DataTypes.STRING,
    allowNull: false
  }
}, {
  sequelize,
  modelName: 'Usuario',
  tableName: 'usuarios'
});

module.exports = Usuario;
