import React, { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { getProdutos } from '../utils/localStorage';
import './ListagemProdutos.css';

const ListagemProdutos = () => {
  const pets = [
    { id: 1, nome: "Tobby", especie: "Cachorro", idade: 4 },
    { id: 2, nome: "Mia", especie: "Gato", idade: 2 },
    { id: 3, nome: "Luna", especie: "Cachorro", idade: 1 },
    { id: 4, nome: "Nino", especie: "Gato", idade: 3 },
    { id: 5, nome: "Bolt", especie: "Cachorro", idade: 5 },
    { id: 6, nome: "Frajola", especie: "Gato", idade: 6 },
    { id: 7, nome: "Pipoca", especie: "Cachorro", idade: 2 },
    { id: 8, nome: "Tom", especie: "Gato", idade: 3 },
    { id: 9, nome: "Mel", especie: "Cachorro", idade: 1 },
    { id: 10, nome: "Bidu", especie: "Cachorro", idade: 7 },
    { id: 11, nome: "Salem", especie: "Gato", idade: 2 },
    { id: 12, nome: "Max", especie: "Cachorro", idade: 3 },
    { id: 13, nome: "Amora", especie: "Gato", idade: 5 },
    { id: 14, nome: "Nina", especie: "Cachorro", idade: 4 },
    { id: 15, nome: "Simba", especie: "Gato", idade: 2 }
  ];

  return (
    <div className="listagem-produtos">
      <div className="container">
        <div className="header-listagem">
          <h1>Galeria de Pets</h1>
           <span className="total-produtos">
              total de pets disponivel 15
            </span>          
        </div>
        
          <div className="produtos-lista">
            {pets.map((pet) => (
              <div className="produto-item" key={pet.id}>
                  <h2>{pet.nome}</h2>
                  <p>Espécie: {pet.especie}</p>
                  <p>Idade: {pet.idade} anos</p>
              </div>
            ))}
        </div>
      </div>
    </div>
  );
};

export default ListagemProdutos;