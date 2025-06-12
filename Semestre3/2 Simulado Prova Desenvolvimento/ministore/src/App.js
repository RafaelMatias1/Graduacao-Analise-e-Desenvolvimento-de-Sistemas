import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './pages/Home';
import CadastroProduto from './pages/CadastroProduto';
import ListagemProdutos from './pages/ListagemProdutos';
import DetalhesProduto from './pages/DetalhesProdutos';
import Header from './components/Header';
import Footer from './components/Footer';
import './App.css';

function App() {
  return (
    <Router>
      <div className="App">
        <Header />
        <main className="main-content">
          <Routes>
            <Route path="/" element={<Home />} />
            <Route path="/cadastro" element={<CadastroProduto />} />
            <Route path="/produtos" element={<ListagemProdutos />} />
            <Route path="/produto/:id" element={<DetalhesProduto />} />
          </Routes>
        </main>
        <Footer />
      </div>
    </Router>
  );
}

export default App;