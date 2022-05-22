import React from "react";
import { View, Text, StyleSheet} from "react-native";
//Importando o componente da pasta './components/component_1.js'
//import C1 from './components/component1';
import C2 from './components/caixas';
import estilos from './styles/estilos.js'

/*
  const componentes = [
    {
      title: 'The Promissed Neverland',
      id:1,
    },
    {
      title: 'The Promissed Neverland2',
      id:2,
    },
    {
      title: 'The Promissed Neverland3',
      id:3,
    },
    {
      title: 'The Promissed Neverland4',
      id:4,
    },
    {
      title: 'The Promissed Neverland5',
      id:5,
    },
  ];

  const Item = ({ title }) => (
    <View>
      <Text>{title}</Text>
    </View>
  );

export default function App() {
    const renderItem = ({ item }) => (
      <Item title={item.title}/>
    );
    return(
      <View>
      <FlatList
      data={componentes}
      renderItem={renderItem}
      />
      </View>
    )
}*/

/*function fexibir(vp1){
  if(vp1 == true){
    return(<Text style={estilos.textoPadrao}>Curso de React Native</Text>)
  }else{
    return(<Text>---</Text>)
  }
  
}*/

const fexibir = (vp1)=>{
  if(vp1){
    return(<Text style={estilos.textoPadrao}>Curso de React Native</Text>)
  }else{
    return(<Text>---</Text>)
  }
}

export default function App() {
  let vexibir=true;
  return(
    <View style={estilos.container}>
      <C2 exibir={vexibir}></C2>
      <Text style={estilos.textoPadrao}>teste 1</Text>
      {fexibir(true)}
    </View>
  );
};
