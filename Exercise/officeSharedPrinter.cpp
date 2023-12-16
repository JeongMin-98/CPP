//
// Created by jeong on 2023-12-12.
//
#include <iostream>
#include <string>
#include <queue>

class Job {
private:
    int id;
    std::string userName;
    int copy;
public:
    Job() = default;
    ~Job() { }

    Job(int job_id, std::string name, int copy_nums) : id(job_id), userName(name), copy(copy_nums) {
        std::cout << "Create Job {" << id << "}" << "requested by" << userName << std::endl;
        std::cout << "Total copy : " << copy << std::endl;
    }

    Job(const Job &other) : id(other.id), userName(other.userName), copy(other.copy) {
        std::cout << "Create Job {" << id << "}" << "requested by" << userName << std::endl;
        std::cout << "Total copy : " << copy << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Job &job) {
        return (os << "Print Job[" << job.id << "]" << " requested by " << job.userName << " total papers : " << job.copy
                   << std::endl);
    }

    bool operator==(const Job& other) const {
        return (id == other.id && userName == other.userName && copy == other.copy);
    }

    bool operator!=(const Job& other) const {
        return !(*this == other); // != 연산자를 == 연산자를 사용하여 정의하는 방식
    }

    Job &operator=(const Job &other){
        std::cout << "copy";
        if (*this != other){
            this->id = other.id;
            this->userName = other.userName;
            this->copy = other.copy;
        }
        return *this;
    }

    Job& operator=(Job&& other) noexcept {
        std::cout << "move!";
        if (this != &other) {
            // 자원 이동 등의 작업을 수행
            this->id = std::move(other.id);
            this->userName = std::move(other.userName);
            this->copy = std::move(other.copy);

            // 이동 후 다른 객체를 유효하지 않은 상태로 만듭니다.
            other.id = 0;
            other.userName = "";
            other.copy = 0;
        }
        return *this;
    }

};

class Printer {
    std::queue<Job> wait;
    int jobId;
public:
    Printer() { jobId = 0; }

    ~Printer() = default;

    void requestJob(std::string user, int copy_nums) {
        wait.push(Job(jobId++, user, copy_nums));
    }

    void performJob() {
        if (wait.size() > 0) {
            std::cout << wait.front();
            wait.pop();
        }
    }
};

int main(){

    Job job1(1, "test", 1);
    Job job2;
    job2 = job1;

    Printer printer;

    printer.requestJob("Jeong", 5);
    printer.requestJob("min", 5);

    printer.performJob();
    printer.performJob();
}