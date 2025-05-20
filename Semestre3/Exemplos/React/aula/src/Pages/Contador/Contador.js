import React, {Component} from 'react'

class Contador extends Component {

    constructor(props){
        super(props)
        this.state = {
            count: 0
        }
    }

    increment = () => {
        this.setState({count: this.state.count + 1})
    }

    render(){
        return(
            <div>
                <h2>Contador: {this.state.count}</h2>
                <button onClick={this.increment}>Incrementar</button>
            </div>
        )
    }

}

export default Contador;