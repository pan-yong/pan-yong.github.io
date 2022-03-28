package qsort

func quickSort(values []int, left, right int) {
	tmp := values[left]
	i, j := left, right
	for i < j {
		for j > i && values[j] >= tmp {
			j--
		}
		if j > i {
			values[i] = values[j]
		}

		for i < j && values[i] <= tmp {
			i++
		}
		if i < j {
			values[j] = values[i]
		}
	}
	values[i] = tmp

	if i - left > 1 {
		quickSort(values, left, i - 1)
	}
	if right - i > 1 {
		quickSort(values, i + 1, right)
	}
}

func QuickSort(values []int) {
	quickSort(values, 0, len(values) - 1)
}