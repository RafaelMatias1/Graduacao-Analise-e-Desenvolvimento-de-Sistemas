import { Link } from "react-router-dom";

const Tabela = (props) => {

    return(
        <section id="tabela">
                    <div id="header_tabela">
                        <div className="nome">Nome</div>
                        <div className="paginas">Páginas</div>
                        <div className="autor">Autor</div>
                        <div className="acoes">Ações</div>
                    </div>
                    <div id="body_tabela">
                        {
                            props.livrosSalvos.map((livro, index) => (
                                <div className="livro" key={index}>
                                    <div className="nome">{livro.nome}</div>
                                    <div className="paginas">{livro.paginas}</div>
                                    <div className="autor">{livro.autor}</div>
                                    <div className="acoes"><Link to="/editar/2">Editar</Link></div>
                                </div>
                            ))
                        }
                    </div>
        </section>
    )
}

export default Tabela;