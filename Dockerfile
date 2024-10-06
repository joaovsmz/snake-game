FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libncurses5-dev

WORKDIR /app
COPY . .

RUN make clean
RUN make all

CMD ["./snake"]