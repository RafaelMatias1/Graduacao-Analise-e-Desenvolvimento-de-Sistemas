import React from 'react';
import { Link } from 'react-router-dom';
import './Home.css';

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

        <section className="features">
          <h2>Por que escolher a MiniStore?</h2>
          <div className="features-grid">
            <div className="feature">
              <h3>🛍️ Catálogo Completo</h3>
              <p>Navegue por todos os produtos cadastrados de forma fácil e intuitiva.</p>
            </div>
            <div className="feature">
              <h3>➕ Cadastro Simples</h3>
              <p>Adicione novos produtos ao nosso catálogo de forma rápida e eficiente.</p>
            </div>
            <div className="feature">
              <h3>💾 Dados Seguros</h3>
              <p>Todos os dados são salvos de forma segura no seu navegador.</p>
            </div>
          </div>
        </section>
      </div>
    </div>
  );
};

export default Home;