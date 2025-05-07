import React from "react";
import { View, Text, ScrollView } from "react-native";
import { labels } from "./labels";
import { styles } from "../Styles/styles";

const UserList = ({ users }) => {
  return (
    <View style={{ marginTop: 20, flex: 1 }}>
      <View style={styles.inputContainerList}>
        <Text style={styles.labelList}>Nome</Text>
        <Text style={styles.labelList}>Telefone</Text>
      </View>

      <ScrollView contentContainerStyle={{ flexGrow: 1 }}>
        {users.map((user, index) => (
          <View key={index} style={styles.userCard}>
            <Text style={styles.userName}>{user.name}</Text>
            <Text style={styles.userPhone}>{user.phone}</Text>
          </View>
        ))}
      </ScrollView>
    </View>
  );
};

export default UserList;