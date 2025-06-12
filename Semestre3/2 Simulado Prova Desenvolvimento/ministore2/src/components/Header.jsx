import React from 'react';
import { Link, useLocation } from 'react-router-dom';
import './Header.css';

const Header = () => {
  const location = useLocation();

  return (
    <header className="header">
      <div className="container">
        <h1 className="logo">
          <Link to="/">MiniStore</Link>
        </h1>
        <nav className="nav">
          <Link 
            to="/" 
            className={location.pathname === '/' ? 'active' : ''}
          >
            Home
          </Link>
          <Link 
            to="/produtos" 
            className={location.pathname === '/produtos' ? 'active' : ''}
          >
            Produtos
          </Link>
          <Link 
            to="/cadastro" 
            className={location.pathname === '/cadastro' ? 'active' : ''}
          >
            Cadastrar
          </Link>
        </nav>
      </div>
    </header>
  );
};

export default Header;