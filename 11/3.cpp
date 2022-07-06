#include <iostream>
#include <map>
#include <string>
#include <set>

int main(){
    std::map<std::pair<std::string, char>, std::string> graph;
    std::set<std::string> terminal_state;
    {
        std::string start, end;
        char go;
        while (std::cin >> start && start != "END"){
            std::cin >> go >> end;
            graph[{start, go}] = end;
        }
        while ((std::cin >> end) && end != "END"){
            terminal_state.insert(end);
        }
    }
    std::string cur_state;
    std::cin >> cur_state;

    char cur_char;
    unsigned long long step = 0;
    bool error = false;
    while((std::cin >> cur_char) && !error){
        // std::cout << cur_char << " " << cur_state << std::endl;
        if(graph.find({cur_state, cur_char}) != graph.end()){
            cur_state = graph.at({cur_state, cur_char});
            ++step;
        } else {
            error = true;
        }
    }
    error = error || terminal_state.find(cur_state) == terminal_state.end();
    std::cout << !error << std::endl;
    std::cout << step << std::endl;
    std::cout << cur_state << std::endl;
}
