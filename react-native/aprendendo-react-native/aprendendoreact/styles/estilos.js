import {StyleSheet} from "react-native";

export default StyleSheet.create({
    container:{
        flex:1,
        backgroundColor:'#fff',
        //Alinhamento vertical
        alignItems:'center',
        //Alinhamento horizontal
        justifyContent:'center'
      },
      textoCurso:{
        color: '#f00',
        fontSize: 15,
      },
      textoTitulo:{
        color: '#00f',
        fontSize: 30,
      },
      textoPadrao:{
        color: '#aaa',
        fontSize: 20,
      }
})