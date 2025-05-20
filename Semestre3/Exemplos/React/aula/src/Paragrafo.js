function Paragrafo(props){

    return (
        <div>
            <p>{props.children}</p>
            <p>{props.idade}</p>
        </div>
    )
}

export default Paragrafo;