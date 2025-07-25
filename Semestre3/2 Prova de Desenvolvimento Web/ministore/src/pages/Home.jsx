import React from 'react';
import { Link } from 'react-router-dom';
import './Home.css';

const Home = () => {
  return (
    <div className="home">
      <div className="container">
        <section className="hero">
          <h1>
            <span className='Bemvindo'>Bem-vindo ao </span>
            <span className='PetFinder'>PetFinder!</span>
          </h1>
          <p className="hero-description">
            Conectamos voce  pets incriveis que estao procurando um novo lar.
          </p>
          <div className="hero-actions">
            <Link to="/produtos" className="btn btn-primary">
              Explorar Galeria
            </Link>
          </div>
        </section>
      </div>
    </div>
  );
};

export default Home;