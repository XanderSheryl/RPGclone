#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "nlohmann/json.hpp"
#include <string>

class JsonParser
{
private:
	std::string m_JsonString;
	nlohmann::json m_json;
public:
	JsonParser();
	JsonParser(const std::string& filepath);

	inline nlohmann::json& GetJSON() { return m_json; }

	inline int GetInt(const std::string& key) { return m_json[key].get<int>(); }
	inline bool GetBool(const std::string& key) { return m_json[key].get<bool>(); }
	inline std::string GetString(const std::string& key) { return m_json[key].get<std::string>(); }

	bool GetKeyPressed(const std::string& key);
	bool GetKeyUp(const std::string& key);
	bool GetKeyDown(const std::string& key);

	void SaveData();
private:
	std::string ReadFromFile(const std::string& filepath);
	void WriteToFile(const std::string& filepath);
	int GetKeyCode(const std::string& j_key);
};

#endif // JSONPARSER_H
