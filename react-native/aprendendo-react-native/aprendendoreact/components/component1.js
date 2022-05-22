import React from "react";
import { Text, StyleSheet } from "react-native";
//Preciso voltar para a pasta raíz
import estilos from '../styles/estilos.js'

//let cor
let nt

export default function component1(props){
    //nt=props.nota
    //cor=props.cor
    return(
        <Text style={estilos.textoCurso}>Primeiro componente em React - curso de {props.curso} com nota {props.nota}</Text>
    )
}

/*const estiloscomponente = StyleSheet.create({
    txt3:{
      color: '#f00',
      fontSize: 10,
    },
});*/

//Posso também remover no cabeçalho e colocar em baixo:
//export default component1()