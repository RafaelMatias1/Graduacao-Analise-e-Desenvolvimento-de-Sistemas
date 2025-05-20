import logo from '../../logo.svg';
import './App.css';
import Link from '../../Link';
import Paragrafo from '../../Paragrafo';


function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <Paragrafo valor="Teste" idade="" >
          <Link />
          <Link />
          <Link />
        </Paragrafo>
        <Link />
      </header>
    </div>
  );
}

export default App;
