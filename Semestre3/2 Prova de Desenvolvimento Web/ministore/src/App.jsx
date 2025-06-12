import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './pages/Home';
import ListagemProdutos from './pages/ListagemProdutos';
import Header from './components/Header';
import './App.css';

function App() {
  return (
    <Router>
      <div className="App">
        <Header />
        <main className="main-content">
          <Routes>
            <Route path="/" element={<Home />} />
            <Route path="/produtos" element={<ListagemProdutos />} />
          </Routes>
        </main>
      </div>
    </Router>
  );
}

export default App;