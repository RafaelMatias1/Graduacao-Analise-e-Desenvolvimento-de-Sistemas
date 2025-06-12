import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { salvarProduto } from '../utils/localStorage';
import './CadastroProduto.css';

const CadastroProduto = () => {
  const [produto, setProduto] = useState({
    nome: '',
    preco: '',
    descricao: ''
  });
  const [loading, setLoading] = useState(false);
  const [mensagem, setMensagem] = useState('');
  const navigate = useNavigate();

  const handleChange = (e) => {
    const { name, value } = e.target;
    setProduto(prev => ({
      ...prev,
      [name]: value
    }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    
    // Validações
    if (!produto.nome.trim()) {
      setMensagem('O nome do produto é obrigatório!');
      return;
    }
    
    if (!produto.preco || parseFloat(produto.preco) <= 0) {
      setMensagem('O preço deve ser um valor válido maior que zero!');
      return;
    }

    setLoading(true);
    setMensagem('');

    try {
      // Removemos a variável novoProduto para corrigir o warning
      salvarProduto({
        ...produto,
        preco: parseFloat(produto.preco)
      });

      setMensagem('Produto cadastrado com sucesso!');
      
      // Limpar formulário
      setProduto({
        nome: '',
        preco: '',
        descricao: ''
      });

      // Redirecionar após 2 segundos
      setTimeout(() => {
        navigate('/produtos');
      }, 2000);

    } catch (error) {
      setMensagem('Erro ao cadastrar produto. Tente novamente.');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="cadastro-produto">
      <div className="container">
        <h1>Cadastrar Novo Produto</h1>
        
        <form onSubmit={handleSubmit} className="produto-form">
          <div className="form-group">
            <label htmlFor="nome">Nome do Produto*</label>
            <input
              type="text"
              id="nome"
              name="nome"
              value={produto.nome}
              onChange={handleChange}
              placeholder="Digite o nome do produto"
              required
            />
          </div>

          <div className="form-group">
            <label htmlFor="preco">Preço*</label>
            <input
              type="number"
              id="preco"
              name="preco"
              value={produto.preco}
              onChange={handleChange}
              placeholder="0.00"
              step="0.01"
              min="0"
              required
            />
          </div>

          <div className="form-group">
            <label htmlFor="descricao">Descrição (opcional)</label>
            <textarea
              id="descricao"
              name="descricao"
              value={produto.descricao}
              onChange={handleChange}
              placeholder="Descreva o produto..."
              rows="4"
            />
          </div>

          {mensagem && (
            <div className={`mensagem ${mensagem.includes('sucesso') ? 'sucesso' : 'erro'}`}>
              {mensagem}
            </div>
          )}

          <button 
            type="submit" 
            className="btn btn-primary"
            disabled={loading}
          >
            {loading ? 'Salvando...' : 'Salvar Produto'}
          </button>
        </form>
      </div>
    </div>
  );
};

export default CadastroProduto;