<?php
require_once __DIR__ . '/../build/SimplePcap.php';

foreach (SimplePcap::findAllDevs() as $name => $description) {
    echo "$name => $description\n";
}

