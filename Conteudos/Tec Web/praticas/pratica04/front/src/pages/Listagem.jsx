function Listagem(props) {
  return (
    <ul>
      <li>
        <span>Nome</span>
        <span>Telefone</span>
        <span>Ações</span>
      </li>
      {props.itens.map((contato) => (
        <li key={contato.id}>
          <span>{contato.nome}</span>
          <span>{contato.telefone}</span>
          <span>
            <button onClick={() => props.onModificar(contato.id)}>
              Modificar
            </button>
            <button onClick={() => props.onRemover(contato.id)}>
              Remover
            </button>
          </span>
        </li>
      ))}
    </ul>
  );
}

export default Listagem;
