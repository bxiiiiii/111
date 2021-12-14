package main

import "fmt"

// 返回一个“返回int的函数”
func fibonacci() func() int {
	pre1 := 0
	pre2 := 1
	return func() int {
		tem := pre1
		pre1 = pre2
		pre2 = tem + pre2
		return tem
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}