import React, { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { getProdutos } from '../utils/localStorage';
import './ListagemProdutos.css';

const ListagemProdutos = () => {
  const [produtos, setProdutos] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const carregarProdutos = () => {
      try {
        const produtosSalvos = getProdutos();
        setProdutos(produtosSalvos);
      } catch (error) {
        console.error('Erro ao carregar produtos:', error);
      } finally {
        setLoading(false);
      }
    };

    carregarProdutos();
  }, []);

  const formatarPreco = (preco) => {
    return new Intl.NumberFormat('pt-BR', {
      style: 'currency',
      currency: 'BRL'
    }).format(preco);
  };

  if (loading) {
    return (
      <div className="listagem-produtos">
        <div className="container">
          <div className="loading">Carregando produtos...</div>
        </div>
      </div>
    );
  }

  return (
    <div className="listagem-produtos">
      <div className="container">
        <div className="header-listagem">
          <h1>Catálogo de Produtos</h1>
          <div className="info-produtos">
            <span className="total-produtos">
              Total: {produtos.length} produto{produtos.length !== 1 ? 's' : ''}
            </span>
            <Link to="/cadastro" className="btn btn-primary">
              Adicionar Produto
            </Link>
          </div>
        </div>

        {produtos.length === 0 ? (
          <div className="sem-produtos">
            <h2>Nenhum produto cadastrado</h2>
            <p>Que tal começar adicionando o primeiro produto?</p>
            <Link to="/cadastro" className="btn btn-primary">
              Cadastrar Primeiro Produto
            </Link>
          </div>
        ) : (
          <div className="produtos-grid">
            {produtos.map((produto) => (
              <div key={produto.id} className="produto-card">
                <div className="produto-info">
                  <h3 className="produto-nome">{produto.nome}</h3>
                  <p className="produto-preco">{formatarPreco(produto.preco)}</p>
                  {produto.descricao && (
                    <p className="produto-descricao-preview">
                      {produto.descricao.length > 100 
                        ? `${produto.descricao.substring(0, 100)}...`
                        : produto.descricao
                      }
                    </p>
                  )}
                </div>
                <div className="produto-actions">
                  <Link 
                    to={`/produto/${produto.id}`} 
                    className="btn btn-secondary"
                  >
                    Ver Detalhes
                  </Link>
                </div>
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
};

export default ListagemProdutos;