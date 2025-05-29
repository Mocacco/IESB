function InputNome(props) {
    return (
    <>
        <label htmlFor="nome">Nome</label>
        <input type="text" id="nome" name="nome" value={props.valor}
        onChange={props.onChange} />
        {props.erro && <p>{props.erro}</p>}
    </>
    );
    }

export default InputNome;