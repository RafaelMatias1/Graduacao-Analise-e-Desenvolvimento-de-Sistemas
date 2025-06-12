import React from 'react';
import { Link } from 'react-router-dom';
import '../styles/Home.css';

const Home = () => {
  return (
    <div className="home">
      <div className="container">
        <section className="hero">
          <h1>Bem-vindo à MiniStore!</h1>
          <p className="hero-description">
            Sua loja virtual completa para descobrir e cadastrar produtos incríveis. 
            Explore nosso catálogo ou adicione seus próprios produtos ao nosso sistema.
          </p>
          <div className="hero-actions">
            <Link to="/produtos" className="btn btn-primary">
              Ver Produtos
            </Link>
            <Link to="/cadastro" className="btn btn-secondary">
              Cadastrar Produto
            </Link>
          </div>
        </section>
      </div>
    </div>
  );
};

export default Home;