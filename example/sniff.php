<?php

require_once __DIR__ . '/../build/SimplePcap.php';

var_dump(SimplePcap::findAllDevs());
$a = new SimplePcap($argv[1], $argv[2], $argv[3]);
while(true) {
    $packet = $a->get();
    $data = $packet->getData();
    $total = $packet->getCapturedLen();
    $bytesPerColumn = 8;
    $columns = 2;
    $bytesPerRow = $bytesPerColumn * $columns;
    $totalRows = ceil($total / $bytesPerRow);
    echo "$packet\n";
    for ($row = 0, $offset = 0; $row < $totalRows; $row++) {
        echo str_pad($row * $bytesPerRow, 5, "0", STR_PAD_LEFT);
        $asciis = array();
        for ($column = 0; $column < $bytesPerRow; $column++) {
            if (($column % $bytesPerColumn) == 0) {
                echo "   ";
            }
            $value = $data[$offset + $column];
            $ordValue = ord($value);
            echo str_pad(sprintf("%x", $ordValue), 2, "0", STR_PAD_LEFT) . " ";
            if ($ordValue > 31 && $ordValue < 128) {
                $asciis[] = $value;
            } else {
                $asciis[] = '.';
            }
        }
        for ($column = 0; $column < $bytesPerRow; $column++) {
            if (($column % $bytesPerColumn) == 0) {
                echo "   ";
            }
            echo $asciis[$column];
        }
        $offset += $bytesPerRow;
        echo "\n";
    }
    echo "\n";
    usleep(100);
}


