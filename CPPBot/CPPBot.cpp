#include <iostream>
#include <fstream>
#include <future>
#include <thread>
#include <chrono>
#include "corefunc.h"
#include "userfunc.h"
#include "json.hpp"
#include <string>
#include <windows.h>
#include <direct.h>


using namespace std;
using json = nlohmann::json;

vector<GrowtopiaBot> bots;
GrowtopiaBot bots1 = { "", "", "", -1 };
GrowtopiaBot bots2 = { "", "", "", -1 };
GrowtopiaBot bots3 = { "", "", "", -1 };

GrowtopiaBot create(string username, string password, string swhost, int swport, string version, string world, string owner) {
	GrowtopiaBot bot = { username, password, swhost, swport };
	bot.gameVersion = version;
	bot.currentWorld = world;
	bot.realOwner = owner;
	bot.userInit();
	bots.push_back(bot);
	return bot;

}
int main() {
	ifstream i("config.json");
	json j;
	i >> j;
	init();
	system("clear");
	string bot1 = j["bot1username"].get<string>(), bot1pass = j["bot1password"].get<string>();
	string bot2 = j["bot2username"].get<string>(), bot2pass = j["bot2password"].get<string>();
	string bot3 = j["bot3username"].get<string>(), bot3pass = j["bot3password"].get<string>();
	string version = j["version"].get<string>();
	string world = j["world"].get<string>();
	string owner = j["owner"].get<string>();

	bots1 = create(bot1, bot1pass, "213.179.209.168", 17198, version, world, owner);
	bots2 = create(bot2, bot2pass, "213.179.209.168", 17198, version, world, owner);
	bots3 = create(bot3, bot3pass, "213.179.209.168", 17198, version, world, owner);
	while (true) {
		bots1.eventLoop();
		bots2.eventLoop();
		bots3.eventLoop();
	}
}
