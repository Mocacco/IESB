import { StyleSheet } from "react-native";

export const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#f5f5f5",
    padding: 20,
  },
  title: {
    fontSize: 18,
    fontWeight: "bold",
    marginTop: 15,
    marginBottom: 20,
    textAlign: "left",
    color: "#333",
  },
  inputContainer: {
    alignSelf: "center",
    flexDirection: "row",
    marginBottom: 10,
  },
  label: {
    flex: 1,
    textAlign: "center",
    fontSize: 16,
    color: "#000",
  },
  inputContainerList: {
    alignSelf: "center",
    flexDirection: "row",
    marginBottom: 20,
  },
  labelList: {
    marginLeft: 10,
    flex: 1,
    textAlign: "justify",
    fontSize: 16,
    color: "#000",
  },
  input: {
    marginRight: 15,
    marginLeft: 15,
    height: 40,
    width: 240,
    borderColor: "#000",
    borderWidth: 1,
    backgroundColor: "#fff",
    alignSelf: "flex-end",
  },
  button: {
    backgroundColor: "#a9c9ff",
    height: 40,
    width: 240,
    justifyContent: "center",
    alignSelf: "flex-end",
    alignItems: "center",
    marginTop: 20,
    marginRight: 15,
    borderColor: "#000",
    borderWidth: 1,
  },
  buttonText: {
    color: "#000",
    fontSize: 16,
    fontWeight: "bold",
  },
  userCard: {
    alignSelf: "center",
    flexDirection: "row",
    marginBottom: 10,
  },
  userName: {
    marginLeft: 10,
    flex: 1,
    textAlign: "justify",
    fontSize: 16,
    color: "#000",
  },
  userPhone: {
    marginLeft: 10,
    flex: 1,
    textAlign: "justify",
    fontSize: 16,
    color: "#000",
  },
  line: {
    borderBottomWidth: 1,
    marginVertical: 20,
  },
});