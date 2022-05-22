import React from "react";
import { Text, StyleSheet, View } from "react-native";

export default function component1(props){
    return(
        //Tamanho 100(tamanho 100 em qualquer smartphone) é diferente de 100%(tela toda)
        //row, column, row-reverse(da esquerda para a direita na tela)/column-reverse
        //Space-evenly é legal
        //Align-itens precisa de um height
        //Align-itens: flex-start -> topo do aplicativo, flex-end -> base do celular
        //FlexWrap: se os filhos não couberem no pai, eles podem se adaptar
        //FlexGrow: como um filho se ajeita com os outros 
        <View style={{width:'100%',height:300,flexDirection:'column', justifyContent:'center'}}>
            {
            props.exibir?
            <View style={{flex:1}}>
                <View style={{flexGrow:1, backgroundColor:'#00f'}}></View>
                <View style={{flexGrow:1, backgroundColor:'#f00'}}></View>
                <View style={{flexGrow:1, backgroundColor:'#00a'}}></View>
            </View>:
            <View style={{flex:1}}>
                <View style={{flexGrow:1, backgroundColor:'#f00'}}></View>
                <View style={{flexGrow:1, backgroundColor:'#aaa'}}></View>
                <View style={{flexGrow:1, backgroundColor:'#00a'}}></View>     
            </View> 
            }
        </View>
    )
}
