package main

import (
	"fmt"
	"flag"
	"bufio"
	"io"
	"os"
	"strconv"
	"time"
	"algorithms/bubblesort"
	"algorithms/qsort"
)

var infile *string = flag.String("i", "infile", "File contains values fo sorting")
var outfile *string= flag.String("o", "outfile", "File to receive sorted values")
var algorithm *string = flag.String("a", "qsort", "Sort algorithm")

func readValues(infile string)(values []int, err error) {
	file, err := os.Open(infile)
	if err != nil {
		fmt.Println("Failed to open input file", infile)
		return
	}
	defer file.Close()

	br := bufio.NewReader(file)

	values = make([]int , 0)

	for {
		line, isPrefix, err1 := br.ReadLine()

		if err1 != nil {
			if err1 != io.EOF {
				err = err1
			}
			break
		}

		if isPrefix {
			fmt.Println("A too long line, seems unexpected.")
			return 
		}

		str := string(line)
		value, err1 := strconv.Atoi(str)

		if err1 != nil {
			err = err1
			return
		}

		values = append(values, value)
	}
	return 
}

func writeValues(values []int, outfile string) error {
	file, err := os.Create(outfile)
	if err != nil {
		fmt.Println("Failed to create the output file ", outfile)
		return err
	}

	defer file.Close()

	for _, value := range values {
		str := strconv.Itoa(value)
		file.WriteString(str + "\n")
	}

	return nil
}

func main() {
	flag.Parse()

	if infile != nil {
		fmt.Println("infile =", *infile, "outfile =", *outfile, "algorithm =", *algorithm)
	}

	values, err := readValues(*infile)
	if err == nil {
		fmt.Println("Read values:", values)
		t1 := time.Now()
		switch *algorithm {
		case "bubblesort":
			bubblesort.BubbleSort(values)
		case "qsort":
			qsort.QuickSort(values)
		}
		t2 := time.Now()

		fmt.Println("The sorting  process costs", t2.Sub(t1), "to complete.")
		writeValues(values, *outfile)

	} else {
		fmt.Println(err)
	}

}

/*
运行命令
 ./sorter -i unsorted.dat -o sorted.dat -a bubblesort
*/