import React from 'react';
import './Footer.css';

const Footer = () => {
  return (
    <footer className="footer">
      <div className="container">
        <div className="footer-content">
          <div className="footer-section">
            <h3>MiniStore</h3>
            <p>Sua loja virtual de confiança</p>
          </div>
          <div className="footer-section">
            <h4>Contato</h4>
            <p>Email: contato@ministore.com</p>
            <p>Telefone: (11) 99999-9999</p>
          </div>
          <div className="footer-section">
            <h4>Endereço</h4>
            <p>Rua Fictícia, 123</p>
            <p>São Paulo - SP</p>
          </div>
        </div>
        <div className="footer-bottom">
          <p>&copy; 2024 MiniStore. Todos os direitos reservados.</p>
        </div>
      </div>
    </footer>
  );
};

export default Footer;